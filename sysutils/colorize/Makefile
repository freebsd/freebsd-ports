# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	colorize
PORTVERSION=	0.3.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.lissyara.su/distfiles/ \
		ftp://p3-800.lissyara.su/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	A robust log colorizer

RUN_DEPENDS=	p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

NO_BUILD=	yes
USE_PERL5=	yes
SUB_FILES=	pkg-message
USES=		shebangfix
SHEBANG_FILES=	colorize

MAN1=		colorize.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/colorizerc|${PREFIX}/etc/colorizerc|' \
		${WRKSRC}/colorize

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/colorize ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc.dist
.if !exists(${PREFIX}/etc/colorizerc)
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc
.endif
	@${INSTALL_MAN} ${WRKSRC}/colorize.1.gz ${PREFIX}/man/man1
	@${SED} -e "s!/usr/local/!${PREFIX}/!" < ${PKGMESSAGE}

.include <bsd.port.mk>
