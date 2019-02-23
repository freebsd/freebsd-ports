# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	duo
PORTVERSION=	1.11.1
CATEGORIES=	security
MASTER_SITES=	https://dl.duosecurity.com/ \
		ZI
DISTNAME=	${PORTNAME}_unix-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Duo unix integration package

LICENSE=	GPLv2

CONFIGURE_ARGS=	--with-pam=${PREFIX}/lib/security --sysconfdir=${PREFIX}/etc \
		--docdir=${DOCSDIR} --includedir=${PREFIX}/include/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		libtool pathfix ssl
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's| /etc| ${PREFIX}/etc|g' \
		${WRKSRC}/pam_duo/pam_duo.8 \
		${WRKSRC}/login_duo/login_duo.8

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/security/pam_duo.so
	${INSTALL_DATA} ${WRKSRC}/login_duo/login_duo.conf \
		${STAGEDIR}${PREFIX}/etc/login_duo.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pam_duo/pam_duo.conf \
		${STAGEDIR}${PREFIX}/etc/pam_duo.conf.sample

.include <bsd.port.mk>
