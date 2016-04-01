# $FreeBSD$

PORTNAME=	icli
DISTVERSION=	0.47
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://finalrewind.org/projects/icli/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Command line interface to Icinga

LICENSE=	ICLI
LICENSE_NAME=	ICLI license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Term-Size>=0:devel/p5-Term-Size \
		icinga:net-mgmt/icinga-core

ICINGADIR?=	/var/spool/icinga

CONFIGURE_ARGS+=	--destdir ${STAGEDIR} \
			--icli-object-file=${ICINGADIR}/objects.cache \
			--icli-status-file=${ICINGADIR}/status.dat \
			--icli-command-file=${ICINGADIR}/icinga.cmd

USES=		perl5
USE_PERL5=	modbuild

post-patch:
		@${REINPLACE_CMD} -i '' 's|/var/[^/]*/icinga|/var/spool/icinga|' \
			${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
