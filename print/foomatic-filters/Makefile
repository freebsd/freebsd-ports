# New ports collection makefile for:	foomatic-rip
# Date created:		2005-01-28
# Whom:			Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-filters
PORTVERSION=	3.0.2
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	Foomatic wrapper scripts

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_A2PS=${LOCALBASE}/bin/a2ps \
		ac_cv_path_CUPS=${LOCALBASE}/libexec/cups \
		ac_cv_path_CUPS_FILTERS=${LOCALBASE}/libexec/cups/filter \
		ac_cv_path_ENSCRIPT=${LOCALBASE}/bin/enscript \
		ac_cv_path_MPAGE=${LOCALBASE}/bin/mpage \
		ac_cv_path_PPR=${LOCALBASE}/lib/ppr \
		ac_cv_path_PPR_INTERFACES=${LOCALBASE}/lib/ppr/interfaces \
		ac_cv_path_PPR_LIB=${LOCALBASE}/lib/ppr/lib \
		ac_cv_path_TEXTTOPS=${LOCALBASE}/libexec/cups/filter/texttops

MAN1=		foomatic-gswrapper.1 foomatic-rip.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
