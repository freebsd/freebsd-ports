# New ports collection makefile for:	cyrus-sasl
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	1.5.15
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://people.FreeBSD.org/~stb/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	hetzels@westbend.net

USE_OPENSSL=	NORSA

.include <bsd.port.pre.mk>

SASL_VER=	${PORTVERSION} #note, may not be needed any more

Y2K=		http://asg.web.cmu.edu/cyrus/imapd/y2k.html

MAN3=		sasl_client.3 sasl_server.3
MAN8=		saslpasswd.8

USE_AUTOCONF=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl \
		--enable-static \
		--enable-login \
		--with-pwcheck=/var/pwcheck \
		--with-rc4=openssl

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+= --enable-gssapi=${KRB5_HOME}
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB}

DOCS=	README README.Y2K TODO INSTALL ChangeLog NEWS

DOC2=	draft-newman-auth-scram-03.txt \
	draft-newman-sasl-anon-00.txt \
	draft-leach-digest-sasl-03.txt \
	rfc1321.txt rfc2095.txt rfc2104.txt rfc2222.txt

HTDOCS=	index programming sysadmin

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${SED}  -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/pwcheck.sh \
		> ${PREFIX}/etc/rc.d/pwcheck.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/pwcheck.sh
	${INSTALL} -d -m 700 -o cyrus -g cyrus /var/pwcheck
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SASL/html
.for file in ${DOCS}
	@${ECHO} share/doc/SASL/${file} >>${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${DOC2}
	@${ECHO} share/doc/SASL/${file} >>${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${PREFIX}/share/doc/SASL/html
	@${ECHO} share/doc/SASL/html/${file}.html >>${TMPPLIST}
.endfor
	@${ECHO} "@dirrm share/doc/SASL/html" >>${TMPPLIST}
	@${ECHO} "@dirrm share/doc/SASL" >>${TMPPLIST}
.endif
.if !defined(KRB5_HOME) || !exists(${KRB5_HOME})
	@${GREP} -v libgssapiv2 ${TMPPLIST} > ${WRKDIR}/tmp.plist
	@${MV} ${WRKDIR}/tmp.plist ${TMPPLIST}
.endif
.if !defined(MAKE_EBONES) || exists(/usr/lib/libkrb.a)
	@${GREP} -v libkerberos4 ${TMPPLIST} > ${WRKDIR}/tmp.plist
	@${MV} ${WRKDIR}/tmp.plist ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
