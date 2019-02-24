# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	regripper
PORTVERSION=	2.8.20190223
CATEGORIES=	security

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for registry analysis in forensics examinations

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Parse-Win32Registry>=0:devel/p5-Parse-Win32Registry

USE_GITHUB=	yes
GH_ACCOUNT=	keydet89
GH_PROJECT=	RegRipper2.8
GH_TAGNAME=	75d3fa9

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	rip.pl
perl_OLD_CMD=	c:\\\\perl\\\\bin\\\\perl.exe
USE_PERL5=	run

PLIST_FILES=	bin/rip.pl
PORTDATA=	plugins/*.pl plugins/all plugins/ntuser plugins/sam \
		plugins/security plugins/software plugins/system \
		plugins/usrclass

post-patch:
	${REINPLACE_CMD} 's|"plugins"|"${DATADIR}/plugins"|' ${WRKSRC}/rip.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rip.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${PORTDATA:S,^,${WRKSRC}/,} ${STAGEDIR}${DATADIR}/plugins

.include <bsd.port.mk>
