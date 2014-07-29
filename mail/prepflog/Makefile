# Created by: Terry Sposato
# $FreeBSD$

PORTNAME=	prepflog
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	http://www.gufonero.com/postfix/

MAINTAINER=	tabmow@freenode.net
COMMENT=	Prepares logfiles in a sanitised format for pflogsumm and awstats

USES=		perl5 shebangfix tar:tgz
NO_BUILD=	yes

SHEBANG_FILES=	prepflog.pl
PLIST_FILES=	bin/prepflog

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
