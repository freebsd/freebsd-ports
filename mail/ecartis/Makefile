# Created by: Trish Lynch <trish@bsdunix.net>
# $FreeBSD$

PORTNAME=	ecartis
DISTVERSION=	1.0.0-snap20060813
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ecartis.net/pub/ecartis/ \
		http://rodrigo.osorio.free.fr/freebsd/distfiles/

MAINTAINER=	jtrigg@spamcop.net
COMMENT=	The Ecartis Listserver / Mailing List Manager

USES=		gmake

USERS=		ecartis
GROUPS=		ecartis

WRKSRC=		${WRKDIR}/ecartis-1.0.0/src
IDEST=		${STAGEDIR}${PREFIX}/${PORTNAME}

SUB_FILES=	pkg-message
PLIST_SUB+=	EC_USER=${USERS} EC_GROUP=${GROUPS}

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${IDEST}
	cd ${WRKDIR}/${PORTNAME}-1.0.0 && ${FIND} * -print | \
		${CPIO} -pdu --quiet ${IDEST}
	${RM} -r ${IDEST}/src/ ${IDEST}/debian ${IDEST}/ecartis.ds[pw]

.include <bsd.port.mk>
