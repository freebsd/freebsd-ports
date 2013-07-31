# Created by: Tim Welch <ports@thepentagon.org>
# $FreeBSD$

PORTNAME=	nzbperl
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.thepentagon.org/local_distfiles/ \
		http://noisybox.net/computers/nzbperl/ \
		ftp://ftp.foss.org.my/pub/FreeBSD/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=

MAINTAINER=	ports@thepentagon.org
COMMENT=	A perl script for downloading nzb files

RUN_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		${LOCALBASE}/bin/uudeview:${PORTSDIR}/converters/uudeview

PLIST_FILES=	bin/nzbperl
NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

.if defined(WITH_SSL)
RUN_DEPENDS+=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
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
