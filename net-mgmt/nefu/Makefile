# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nefu
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://rsug.itd.umich.edu/software/nefu/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network monitoring daemon

USES=		tar:tgz
USE_RC_SUBR=	nefu
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=	YACC=${YACC} \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} \
		--without-sasl \
		--without-zlib \
		--without-shelltests

USERS=		nefu
GROUPS=		nefu

USE_OPENSSL=	yes
OPTIONS_DEFINE=	LDAP HTML
HTML_DESC=	HTML support
OPTIONS_SUB=	yes

DBDIR=		/var/db/nefu

LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}/lib
LDAP_CONFIGURE_OFF=	--without-ldap
LDAP_USE=		OPENLDAP=yes

HTML_CONFIGURE_ON=	--with-html=${WWWDIR}
HTML_CONFIGURE_OFF=	--without-html

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nefu.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nefu.conf.4 ${STAGEDIR}${PREFIX}/man/man4

post-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
