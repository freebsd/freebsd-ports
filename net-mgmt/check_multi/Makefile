# $FreeBSD$

PORTNAME=	check_multi
PORTVERSION=	0.19
CATEGORIES=	net-mgmt
#MASTER_SITES=	http://my-plugin.de/${PORTNAME}/
#PKGNAMEPREFIX=	nagios-
#DISTNAME=	${PORTNAME}-${PORTVERSION}.current
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-purpose wrapper plugin for Nagios

LICENSE=	GPLv2

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLUGIN_DIR=	libexec/nagios

SHEBANG_FILES=	check_multi

OPTIONS_DEFINE=	EXAMPLES

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_multi ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/contrib -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -

.include <bsd.port.mk>
