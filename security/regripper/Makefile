# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	regripper
DISTVERSION=	2.8
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	rrv${DISTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for registry analysis in forensics examinations

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Parse-Win32Registry>=0:${PORTSDIR}/devel/p5-Parse-Win32Registry

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		dos2unix perl5 zip shebangfix
SHEBANG_FILES=	rip.pl
perl_OLD_CMD=	c:\\\\perl\\\\bin\\\\perl.exe
USE_PERL5=	run

PLIST_FILES=	bin/rip.pl

post-patch:
	${REINPLACE_CMD} -e 's|plugindir = $$str|plugindir = "${DATADIR}"| ; \
		s|require "plugins/|require "${DATADIR}plugins/|' ${WRKSRC}/rip.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rip.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
