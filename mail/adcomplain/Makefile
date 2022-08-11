PORTNAME=	adcomplain
PORTVERSION=	3.52
CATEGORIES=	mail news
MASTER_SITES=	http://www.rdrop.com/users/billmc/
DISTNAME=	${PORTNAME}.pl
EXTRACT_SUFX=	.uu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complain about inappropriate commercial use (f.e. SPAM) of usenet/e-mail

USES=		perl5 shebangfix
SHEBANG_FILES=	adcomplain.pl

EXTRACT_CMD=	/usr/bin/uudecode
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/adcomplain

# fix-shebang normally runs before the patches in ${FILESDIR} are applied.  In
# this case, we need it to run after, so that it can fix the right shebang.
TARGET_ORDER_OVERRIDE=	750:fix-shebang

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/adcomplain.pl \
		${STAGEDIR}${PREFIX}/bin/adcomplain

.include <bsd.port.mk>
