# New ports collection makefile for:	cyrus-sasl
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	1.5.21
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://people.FreeBSD.org/~stb/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	hetzels@westbend.net

USE_OPENSSL=	RSA

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

Y2K=		http://asg.web.cmu.edu/cyrus/imapd/y2k.html

MAN3=		sasl.3 sasl_authorize_t.3 sasl_callbacks.3 sasl_checkpass.3 \
		sasl_client_init.3 sasl_client_new.3 sasl_client_start.3 sasl_client_step.3 \
		sasl_decode.3 sasl_done.3 sasl_encode.3 sasl_errstring.3 sasl_getopt_t.3 \
		sasl_getpath_t.3 sasl_getprop.3 sasl_getsecret_t.3 sasl_getsimple_t.3 \
		sasl_listmech.3 sasl_log_t.3 \
		sasl_server_init.3 sasl_server_new.3 sasl_server_start.3 sasl_server_step.3 \
		sasl_setprop.3 sasl_usererr.3
MAN8=		sasldblistusers.8 saslpasswd.8

USE_AUTOCONF=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl \
		--enable-static \
		--enable-login \
		--with-pwcheck=/var/pwcheck \
		--with-rc4=openssl

# JavaSASL is currently Broken
#JAVADIR=        jdk1.1.8
#JAVALIBDIR=     ${PREFIX}/${JAVADIR}/lib/i386/green_threads/

#.if defined(USE_JAVA) || exists(${LOCALBASE}/${JAVADIR}/bin/java)
#BUILD_DEPENDS=  ${LOCALBASE}/${JAVADIR}/bin/java:${PORTSDIR}/java/jdk
#CONFIGURE_ARGS+= --with-java \
#		 --with-javabase=${LOCALBASE}/include
#
#CONFIGURE_ENV=	JAVAC="${LOCALBASE}/${JAVADIR}/bin/javac" \
#		JAVAH="${LOCALBASE}/${JAVADIR}/bin/javah" \
#		JAVADOC="${LOCALBASE}/${JAVADIR}/bin/javadoc"
#.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+= --enable-gssapi=${KRB5_HOME}
.else
CONFIGURE_ARGS+= --disable-gssapi
GSSAPI=	"@comment "
.endif

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+= --enable-krb4
.else
CONFIGURE_ARGS+= --disable-krb4
EBONES=	"@comment "
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB}

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

DOC2=	draft-leach-digest-sasl-05.txt \
	draft-newman-auth-scram-03.txt \
	rfc1321.txt rfc2095.txt rfc2104.txt \
	rfc2222.txt rfc2245.txt

HTDOCS=	gssapi index programming sysadmin

.if defined(NOPORTDOCS)
NODOCS=	"@comment "
.endif

PLIST_SUB=	PREFIX=${PREFIX} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		NOPORTDOCS=${NODOCS}

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	@${SED}  -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/pwcheck.sh \
		> ${PREFIX}/etc/rc.d/pwcheck.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/pwcheck.sh
	${INSTALL} -d -m 700 -o cyrus -g cyrus /var/pwcheck
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SASL/html
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${PREFIX}/share/doc/SASL/html
.endfor
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.elif ${PREFIX} != ${LOCALBASE}
# Save PREFIX so that it can be used during make install
.BEGIN:
	@echo "PREFIX=	${PREFIX}" > ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.post.mk>
