# Ports collection Makefile for:  bugmenot
# Date created:			  Tue May 24, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	bugmenot
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	xsidebar/mods
DISTNAME=	${PORTNAME}-${PORTVERSION}-mod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	${GECKO} extension to bypass compulsory web registration

PLIST_FILES=	%%MOZDIR%%/chrome/bugmenot.jar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/browser/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/bugmenot.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>
