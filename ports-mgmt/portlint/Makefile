# Created by: Jun-ichiro itojun Hagino <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	portlint
PORTVERSION=	2.14.6
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Verifier for FreeBSD port directory

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src
USES=		perl5
USE_PERL5=	run

SRC=		${.CURDIR}/src

PLIST_FILES=	bin/portlint \
		man/man1/portlint.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_FILES+=	%%EXAMPLESDIR%%/portlintgrep
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/portlint.pl
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/portlintgrep.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portlint.pl \
	    ${STAGEDIR}${PREFIX}/bin/portlint
	${INSTALL_MAN} ${WRKSRC}/portlint.1 \
	    ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m ${BINMODE} -d \
	    ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/portlintgrep.pl \
	    ${STAGEDIR}${EXAMPLESDIR}/portlintgrep
.endif

.include <bsd.port.mk>
