# New ports collection makefile for:	cyrus-sasl
# Version required:			1.5.13
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

DISTNAME=	cyrus-sasl-${SASL_VER}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://www.freebsd.org/~stb/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	hetzels@westbend.net

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl
LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

SASL_VER=	1.5.13

RESTRICTED=     "Contains cryptography"

Y2K=		http://asg.web.cmu.edu/cyrus/imapd/y2k.html

MAN3=		sasl_client.3 sasl_server.3
MAN8=		saslpasswd.8

USE_AUTOCONF=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS= \
		--prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl \
		--enable-static \
		--with-rc4=openssl

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+= --enable-gssapi=${KRB5_HOME}
.endif

CONFIGURE_ARGS+= \
		--with-pwcheck=/var/pwcheck

#  --with-dbpath=PATH      set the DB path to use [/etc/sasldb]
#  --with-pam=DIR          use PAM (rooted in DIR) [yes]
#  --with-pwcheck=DIR      enable use of the pwcheck daemonusing statedir DIR
#  --enable-cram           enable CRAM-MD5 authentication [yes]
#  --enable-scram          enable SCRAM-MD5 authentication [no]
#  --enable-digest         enable DIGEST-MD5 authentication [yes]
#  --enable-krb4           enable KERBEROS_V4 authentication [yes]
#  --enable-gssapi         enable GSSAPI authentication [yes]
#  --enable-anon           enable ANONYMOUS authentication [yes]
#  --enable-plain          enable PLAIN authentication [yes]
#  --with-rc4=DIR          use rc4 (look in DIR) [yes]

DOCS=	README README.Y2K TODO INSTALL ChangeLog NEWS

DOC2=	draft-newman-auth-scram-03.txt \
	draft-newman-sasl-anon-00.txt \
	draft-leach-digest-sasl-03.txt \
	rfc1321.txt rfc2095.txt rfc2104.txt rfc2222.txt

HTDOCS=	index programming sysadmin

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
#       ${INSTALL} -d -m 700 -o cyrus -g cyrus /var/pwcheck
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SASL/html
.for file in ${DOCS}
	@${ECHO} share/doc/SASL/${file} >>${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${DOC2}
	@${ECHO} share/doc/SASL/${file} >>${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${PREFIX}/share/doc/SASL/html
	@${ECHO} share/doc/SASL/html/${file}.html >>${TMPPLIST}
.endfor
	@${ECHO} "@dirrm share/doc/SASL/html" >>${TMPPLIST}
	@${ECHO} "@dirrm share/doc/SASL" >>${TMPPLIST}
.endif
.if !defined(KRB5_HOME) || !exists(${KRB5_HOME})
	${GREP} -v libgssapiv2 ${TMPPLIST} > ${WRKDIR}/tmp.plist
	${MV} ${WRKDIR}/tmp.plist ${TMPPLIST}
.endif
.if !defined(MAKE_EBONES) || exists(/usr/lib/libkrb.a)
	${GREP} -v libkerberos4 ${TMPPLIST} > ${WRKDIR}/tmp.plist
	${MV} ${WRKDIR}/tmp.plist ${TMPPLIST}
.endif

.include <bsd.port.mk>
