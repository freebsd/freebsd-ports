# New ports collection makefile for:    nagiosgrapher
# Date created:                         03 Nov 2009
# Whom:                                 Cristiano Rolim <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	nagiosgrapher
PORTVERSION=	1.7.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NagiosGrapher-${PORTVERSION}/ \
		https://www.nagiosforge.org/gf/download/frsrelease/135/285/
DISTNAME=	NagiosGrapher-${PORTVERSION}

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Collects the output from Nagios and generates graphs

BUILD_DEPENDS=	\
	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool \
	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
	${SITE_PERL}/Calendar/Simple.pm:${PORTSDIR}/devel/p5-Calendar-Simple \
	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	YES

USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

USE_AUTOTOOLS=	autoconf:268

PERL_MODULES=	${SITE_PERL}

CONFIGURE_ARGS+=--with-layout=FreeBSD

post-patch:
	@${REINPLACE_CMD} -e 's|5.8.8|${PERL_VERSION}|g' ${WRKSRC}/config.layout

.include <bsd.port.mk>
