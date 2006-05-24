# New ports collection makefile for:	nefu
# Date created:				17.10.2003
# Whom:					Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nefu
PORTVERSION=	1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://rsug.itd.umich.edu/software/nefu/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	A network monitoring daemon

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib" \
			YACC=${YACC} \
			OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE} --without-html \
			--without-shelltests

USE_OPENSSL=	yes
OPTIONS=	LDAP "Enable OpenLDAP support" off

MAN1=		nefu.1
MAN4=		nefu.conf.4
PLIST_FILES=	bin/nefu

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lsasl2||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lssl|-lssl -lcrypto|' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nefu.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nefu.conf.4 ${PREFIX}/man/man4

.include <bsd.port.post.mk>
