# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	textmail
PORTVERSION=	20070803
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://raf.org/textmail/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts e-mail attachments to plain-text

RUN_DEPENDS=	antiword:${PORTSDIR}/textproc/antiword \
		catdoc:${PORTSDIR}/textproc/catdoc \
		xls2csv:${PORTSDIR}/textproc/catdoc \
		lynx:${PORTSDIR}/www/lynx \
		${LOCALBASE}/libexec/xpdf/pdftotext:${PORTSDIR}/graphics/xpdf

USES=		perl5
PLIST_FILES=	bin/${PORTNAME}
NO_WRKSUBDIR=	yes
MAN1=	${PORTNAME}.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '3s|^|\${.newline}$$ENV{'PATH'} = "${LOCALBASE}/libexec/xpdf:$$ENV{'PATH'}";\${.newline}|' ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/&&pod2man ${PORTNAME}>${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
