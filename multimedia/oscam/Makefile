# Created by: Franz Bettag <franz@bett.ag>
# $FreeBSD$

PORTNAME=	oscam
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://el8.nl/~fbettag/oscam/

MAINTAINER=	franz@bett.ag
COMMENT=	Softcam software to decrypt digital tv channels

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

USES=		gmake ssl tar:bzip2
USE_RC_SUBR=	oscam
MAKE_ARGS+=	HOSTCC=clang CC=clang

.if target(gen-dist)
FETCH_DEPENDS+=	svn:devel/subversion
.endif
SVN_REV=	11062
SVN_SRC=	http://www.streamboard.tv/svn/oscam/trunk

do-install:
	${RM} ${WRKSRC}/Distribution/*.debug
	${INSTALL_PROGRAM} ${WRKSRC}/Distribution/${PORTNAME}-${PORTVERSION}-* ${STAGEDIR}${PREFIX}/bin/oscam
	${INSTALL_MAN} ${WRKSRC}/Distribution/doc/man/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/Distribution/doc/man/*.5 ${STAGEDIR}${PREFIX}/man/man5/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/Distribution/doc/example/* ${STAGEDIR}${EXAMPLESDIR}/

gen-dist:
	${MKDIR} ${WRKDIR}
	svn export --force -r ${SVN_REV} ${SVN_SRC} ${WRKSRC}
	${TAR} -cvy -C ${WRKDIR} -f ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}

.include <bsd.port.mk>
