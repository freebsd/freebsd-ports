# Created by: Cristiano Rolim <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	nagiosgrapher
PORTVERSION=	1.7.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NagiosGrapher-${PORTVERSION}/ \
		https://www.nagiosforge.org/gf/download/frsrelease/135/285/
DISTNAME=	NagiosGrapher-${PORTVERSION}

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Collects the output from Nagios and generates graphs

DEPRECATED=	Deprecated upstream. Please use net-mgmt/pnp instead
EXPIRATION_DATE=2013-01-30

BUILD_DEPENDS=	\
	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
	convert:${PORTSDIR}/graphics/ImageMagick \
	p5-URI>=0:${PORTSDIR}/net/p5-URI \
	p5-Calendar-Simple>=0:${PORTSDIR}/devel/p5-Calendar-Simple \
	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	YES

USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

USE_AUTOTOOLS=	autoconf

PERL_MODULES=	${SITE_PERL}

CONFIGURE_ARGS+=--with-layout=FreeBSD

post-patch:
	@${REINPLACE_CMD} -e 's|5.8.8|${PERL_VERSION}|g' ${WRKSRC}/config.layout

.include <bsd.port.mk>
