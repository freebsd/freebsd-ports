# New ports collection makefile for:   kxicq
# Date created:        10 March 2000
# Whom:                Andrey Novikov <andrey@novikov.com>
#
# $FreeBSD$

PORTNAME=	kxicq
PORTVERSION=	0.3.97b
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-03132000

MAINTAINER=	andrey@novikov.com

USE_KDELIBS_VER=1
USE_GMAKE=	yes
USE_LIBTOOL=	yes

DIST_SUBDIR=	kxicq

.if defined(ADDITIONAL_SKINS)
SKINS=		GoldBlue blueplanet ciasa_boark_inc cyrus
PLIST=		${WRKDIR}/PLIST
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} GoldBlue.tar.gz \
		blueplanet-0.1.tar.gz cyrustheme.tar.gz \
		ciasa_boark_inc-0.4.tar.gz
.endif

pre-fetch:
.if !defined(ADDITIONAL_SKINS)
	@${ECHO}
	@${ECHO} "You may define INSTALL_ADDITIONAL_SKINS (make ADDITIONAL_SKINS=YES)"
	@${ECHO} "to fetch and install additional skins for kxicq."
	@${ECHO}
	@sleep 1
.endif

post-extract:
.if defined(ADDITIONAL_SKINS)
	@${MKDIR} ${WRKDIR}/ciasa_boark_inc
	@${TAR} -xz -C ${WRKDIR}/ciasa_boark_inc -f ${WRKDIR}/ciasa_boark_inc-0.4.tar.gz
.endif

pre-install:
.if defined(ADDITIONAL_SKINS)
	@if [ -f ${PLIST} ] ; then \
		${RM} ${PLIST} ; fi
.for skin in ${SKINS}
	@for f in ${WRKDIR}/${skin}/* ; do \
		file=`${BASENAME} $$f`; \
		${ECHO} share/apps/kxicq/skins/${skin}/$$file >> ${PLIST} ; done
	@${ECHO} @dirrm share/apps/kxicq/skins/${skin} >> ${PLIST}.dirrm
.endfor
	@${CAT} ${PLIST}.dirrm >> ${PLIST} && ${RM} ${PLIST}.dirrm
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
.endif

post-install:
.if defined(ADDITIONAL_SKINS)
	@${ECHO} "===>   Installing kxicq additional skins"
.for skin in ${SKINS}
	@${MKDIR} ${PREFIX}/share/apps/kxicq/skins/${skin}
	${INSTALL_DATA} ${WRKDIR}/${skin}/* ${PREFIX}/share/apps/kxicq/skins/${skin}
.endfor
.endif

.include <bsd.port.mk>
