# New ports collection makefile for:	foomatic-rip
# Date created:		2005-01-28
# Whom:			Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-filters
PORTVERSION=	3.0.2
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	Foomatic wrapper scripts

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter \
		cups-config:${PORTSDIR}/print/cups-base \
		enscript:${PORTSDIR}/print/enscript-letter \
		mpage:${PORTSDIR}/print/mpage

USE_PERL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_PPR=${LOCALBASE}/lib/ppr \
		ac_cv_path_PPR_INTERFACES=${LOCALBASE}/lib/ppr/interfaces \
		ac_cv_path_PPR_LIB=${LOCALBASE}/lib/ppr/lib

.include <bsd.port.mk>
