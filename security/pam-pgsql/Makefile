# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	pam-pgsql
PORTVERSION=	0.7.3.1
PORTREVISION=	4
CATEGORIES=	security databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.7/

MAINTAINER=	berend@pobox.com
COMMENT=	PAM module for authenticating with PostgreSQL

LICENSE=	GPLv2

LIB_DEPENDS=	libmhash.so:${PORTSDIR}/security/mhash \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USES=		libtool pgsql
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
