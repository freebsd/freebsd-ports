# New ports collection makefile for:	nefu
# Date created:				17.10.2003
# Whom:					Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nefu
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://rsug.itd.umich.edu/software/nefu/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A network monitoring daemon

USE_RC_SUBR=	nefu
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib" \
			YACC=${YACC} \
			OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE} \
			--without-sasl \
			--without-zlib \
			--without-shelltests

USERS=		nefu
GROUPS=		nefu

USE_OPENSSL=	yes
OPTIONS=	LDAP "Enable OpenLDAP support" off \
		HTML "Enable HTML support" off

MAN1=		nefu.1
MAN4=		nefu.conf.4
DBDIR=		/var/db/nefu
PLIST_FILES=	bin/nefu

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined(WITH_HTML)
CONFIGURE_ARGS+=--with-html=${WWWDIR}
PLIST_FILES+=	"@unexec rm -rf "%D/%%WWWDIR%%" 2> /dev/null || true"
.else
CONFIGURE_ARGS+=--without-html
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lsasl2||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lssl|-lssl -lcrypto|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|== x_|= x_|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|== x_|= x_|' \
		${WRKSRC}/libsnet/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nefu.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nefu.conf.4 ${PREFIX}/man/man4

post-install:
.if defined(WITH_HTML)
	${MKDIR} ${WWWDIR}
	${CHOWN} -R ${USERS}:${GROUPS} ${WWWDIR}
.endif
	${MKDIR} ${DBDIR}
	${CHOWN} -R ${USERS}:${GROUPS} ${DBDIR}

.include <bsd.port.post.mk>
