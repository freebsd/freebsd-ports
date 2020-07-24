# Created by: Masafumi Otsune <info@otsune.com>
# $FreeBSD$

PORTNAME=	bsfilter
PORTVERSION=	1.0.19
PORTREVISION=	3
CATEGORIES=	mail ruby
MASTER_SITES=	OSDN/bsfilter

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bayesian spam filter written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-gdbm>=2.0.0,2:databases/rubygem-gdbm

NO_BUILD=	yes
USE_RUBY=	yes
USES=		shebangfix tar:tgz
SHEBANG_FILES=	bsfilter/bsfilter

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for FILE in bsfilter.conf.sample dot-qmail.sample
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for DIR in mda mua
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
