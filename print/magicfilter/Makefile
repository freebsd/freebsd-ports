# New ports collection makefile for:	magicfilter
# Date created:		24 Mar 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	magicfilter
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= system/printing

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Customizable, extensible automatic printer filter

USE_GHOSTSCRIPT=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN8=		magicfilter.8

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

# install filters and examples
post-install:
	${MKDIR} ${PREFIX}/libexec/magicfilter
.for FILTER in 	bj10e-filter bj200-filter cps300-filter cps400-filter \
		cps600-filter cpsonly300-filter cpsonly400-filter \
		cpsonly600-filter deskjet-filter dj500-filter \
		dj500c-filter dj550c-filter epson9-filter epson9c-filter \
		epsonlq-filter epsonlqc-filter ibmpro-filter jetp3852-filter \
		la50-filter la75-filter laserjet-filter laserjetlo-filter \
		lbp8-filter lj250-filter ljet2p-filter ljet2plo-filter \
		ljet3-filter ljet4-filter ljet4l-filter ljet4m-filter \
		ljet4ml-filter ljetplus-filter ljetpluslo-filter ln03-filter \
		m8510-filter necp6-filter oki182-filter pj-filter pjxl-filter \
		pjxl300-filter ps300-filter ps400-filter ps600-filter \
		psonly300-filter psonly400-filter psonly600-filter \
		r4081-filter tek4693-filter tek4696-filter
	${INSTALL_SCRIPT} ${WRKSRC}/filters/${FILTER} \
			   ${PREFIX}/libexec/magicfilter/
	${MKDIR} ${PREFIX}/share/examples/magicfilter
	${INSTALL_DATA} ${FILESDIR}/printcap.sample \
			${PREFIX}/share/examples/magicfilter/
.endfor

.include <bsd.port.post.mk>
