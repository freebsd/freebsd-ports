# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	subtitleoffsetmodificator
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	multimedia textproc converters
MASTER_SITES=	http://thomas.enix.org/pub/code/perl/
DISTFILES=	subtitle-offset-modificator.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle offset modificator

LICENSE=	GPLv2+

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/subtitle-offset-modificator
SHEBANG_FILES=	subtitle-offset-modificator.pl

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/subtitle-offset-modificator.pl ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/subtitle-offset-modificator.pl \
		${STAGEDIR}${PREFIX}/bin/subtitle-offset-modificator

.include <bsd.port.mk>
