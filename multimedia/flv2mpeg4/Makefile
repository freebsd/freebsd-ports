# New ports collection makefile for:   flv2mpeg4
# Date created:			22 August 2007
# Whom:					spam@rm-rf.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	flv2mpeg4
DISTVERSION=	20061129
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://src4.narod.ru/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Fast and less lossy FLV to MPEG4(AVI/MOV/MP4/MP3/3GP) converter

LIB_DEPENDS=	avformat:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/flv2mpeg4

WRKSRC=		${WRKDIR}/${PORTNAME}/src

SVNROOT=	https://vixynet.svn.sourceforge.net/svnroot/vixynet

gen-dist:
	@if [ ! -f ${LOCALBASE}/bin/svn ]; then \
		${ECHO_CMD}	"ERROR: You need to install devel/subversion for gen-dist target"; \
		${FALSE}; \
	fi
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${WRKDIR}/svn; \
		cd ${WRKDIR}/svn &&	svn co ${SVNROOT} vixynet; \
		cd ${WRKDIR}/svn/vixynet/trunk && \
		${TAR} cfj ${_DISTDIR}${DISTFILES} flv2mpeg4; \
		cd ${WRKDIR} && ${RM} -rf svn; \
		cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} makesum; \
	fi

.include <bsd.port.mk>
