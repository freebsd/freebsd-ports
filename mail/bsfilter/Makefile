PORTNAME=	bsfilter
PORTVERSION=	1.0.19
PORTREVISION=	4
CATEGORIES=	mail ruby
MASTER_SITES=	OSDN/bsfilter

MAINTAINER=	nyan@FreeBSD.org
COMMENT=	Bayesian spam filter written in Ruby
WWW=		https://osdn.net/projects/bsfilter/

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-gdbm>=2.0.0,2:databases/rubygem-gdbm \
		rubygem-sdbm>=1.0.0:databases/rubygem-sdbm

USES=		ruby shebangfix tar:tgz
SHEBANG_FILES=	bsfilter/bsfilter
NO_BUILD=	yes

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
