# Created by: ijliao
# $FreeBSD$

PORTNAME=	help2man
PORTVERSION=	1.47.12
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically generating simple manual pages from program output

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	NLS

USES=		gmake localbase perl5 tar:xz

GNU_CONFIGURE=	yes

INFO=		${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

NLS_BUILD_DEPENDS=	p5-Locale-gettext>=0:devel/p5-Locale-gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	lib/bindtextdomain.so
NLS_RUN_DEPENDS=	p5-Locale-gettext>=0:devel/p5-Locale-gettext
NLS_USES=		gettext
NLS_VARS=		CONFIGURE_FAIL_MESSAGE="Rebuild lang/${PERL_PORT} and devel/p5-Locale-gettext manually before contacting maintainer."

.for lang in de es fr pl pt_BR sv ta uk zh_CN
NLS_INFO+=		${PORTNAME}-${lang}
.endfor

.for lang in da de el eo es fi fr hr hu it ja nb pl pt_BR ru sr sv ta uk vi zh_CN
NLS_PLIST_FILES+=	man/${lang}/man1/${PORTNAME}.1.gz \
			share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/^pkglibdir/ s|/${PORTNAME}$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
