PORTNAME=	textmail
PORTVERSION=	20070803
PORTREVISION=	45
CATEGORIES=	mail
MASTER_SITES=	http://raf.org/textmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts e-mail attachments to plain-text
WWW=		https://raf.org/textmail/

RUN_DEPENDS=	antiword:textproc/antiword \
		catdoc:textproc/catdoc \
		xls2csv:textproc/catdoc \
		lynx:www/lynx \
		pdftotext:graphics/poppler-utils

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e '3s|^|\${.newline}$$ENV{'PATH'} = "${LOCALBASE}/libexec/xpdf:$$ENV{'PATH'}";\${.newline}|' ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/&&pod2man ${PORTNAME}>${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
