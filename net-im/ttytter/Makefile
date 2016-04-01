# Created by: Julian C. Dunn <jdunn@aquezada.com>
# $FreeBSD$

PORTNAME=	ttytter
PORTVERSION=	2.1.00
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	http://www.floodgap.com/software/ttytter/dist2/:dist \
		http://www.floodgap.com/software/ffsl/:license
DISTFILES=	${PORTVERSION}.txt:dist license.txt:license
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Command-line Twitter client in Perl

LICENSE=	FFSL
LICENSE_NAME=	Floodgap Free Software License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	curl:ftp/curl \
		p5-TimeDate>=0:devel/p5-TimeDate

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${PORTVERSION}.txt

OPTIONS_DEFINE=	READLINE RLTTYTTER
OPTIONS_DEFAULT=READLINE
READLINE_DESC=	Include rich readline support
RLTTYTTER_DESC=	Use T::R::TTYtter readline driver (beta!)

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
RUN_DEPENDS+=	p5-ReadLine-Perl>=0:devel/p5-ReadLine-Perl
.endif

.if ${PORT_OPTIONS:MRLTTYTTER}
RUN_DEPENDS+=	p5-ReadLine-TTYtter>=1.4:devel/p5-ReadLine-TTYtter
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PORTVERSION}.txt ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/license.txt ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTVERSION}.txt ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
