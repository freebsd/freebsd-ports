# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	pam-pgsql
PORTVERSION=	0.7.3.1
CATEGORIES=	security databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.7/

MAINTAINER=	berend@pobox.com
COMMENT=	PAM module for authenticating with PostgreSQL

LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_PGSQL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--libdir=/usr/lib

.include <bsd.port.options.mk>

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${PKGMESSAGE}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGELOG \
		${WRKSRC}/COPYRIGHT ${DOCSDIR}
.endif

.include <bsd.port.mk>
