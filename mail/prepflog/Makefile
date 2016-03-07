# Created by: Terry Sposato
# $FreeBSD$

PORTNAME=	prepflog
PORTVERSION=	0.4.1
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prepares logfiles in a sanitised format for pflogsumm and awstats

LICENSE=	GPLv2+

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	johnfawcett

SHEBANG_FILES=	prepflog.pl
PLIST_FILES=	bin/prepflog man/man1/prepflog.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${LOCALBASE}/bin/pod2man ${WRKSRC}/prepflog.pl > \
		${STAGEDIR}${MANPREFIX}/man/man1/prepflog.1

.include <bsd.port.mk>
