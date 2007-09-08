# New ports collection makefile for:	nzbperl
# Date created:				20 May 2006
# Whom:					Tim Welch <ports@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	nzbperl
PORTVERSION=	0.6.8
CATEGORIES=	news
MASTER_SITES=	http://www.thepentagon.org/local_distfiles/ \
		http://noisybox.net/computers/nzbperl/ \
		ftp://ftp.foss.org.my/pub/FreeBSD/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=

MAINTAINER=	ports@thepentagon.org
COMMENT=	A perl script for downloading nzb files

RUN_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${LOCALBASE}/bin/uudeview:${PORTSDIR}/converters/uudeview

PLIST_FILES=	bin/nzbperl
NO_BUILD=	yes
USE_PERL5_RUN=	yes

.if defined(WITH_SSL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}
	@${REINPLACE_CMD} -e \
		"s,#!/usr/bin/perl -w,#!/usr/local/bin/perl -w," \
		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
