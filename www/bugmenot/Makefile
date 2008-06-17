# Ports collection Makefile for:  bugmenot
# Date created:			  Tue May 24, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	bugmenot
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://extensions.roachfiend.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}_2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	${GECKO} extension to bypass compulsory web registration

BROKEN=		Unfetchable
DEPRECATED=	1.4 seems the latest version installable with seamonkey, but it does not work
EXPIRATION_DATE=2008-08-17

PLIST_FILES=	%%MOZDIR%%/chrome/bugmenot.jar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/browser/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/bugmenot.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>
