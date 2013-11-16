# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	sysgather
DISTVERSION=	1.0pre10
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/sysgather/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep configuration files under version control

LICENSE=	BSD

BUILD_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MEXAMPLES)
MAKE_ENV+=	EXAMPLESDIR="${WRKDIR}"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*/perl|#!${PERL}|' ${WRKSRC}/sysgather.pl

.include <bsd.port.mk>
