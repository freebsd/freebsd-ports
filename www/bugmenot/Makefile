# Ports collection Makefile for:  bugmenot
# Date created:			  Tue May 24, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	bugmenot
PORTVERSION=	0.6.2
CATEGORIES=	www
MASTER_SITES=	http://extensions.roachfiend.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	Mozilla extension to bypass compulsory web registration

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/bugmenot.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>
