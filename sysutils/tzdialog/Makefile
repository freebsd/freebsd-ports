PORTNAME=	tzdialog
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set the local timezone using dialog(1) or Xdialog(1)
WWW=		https://druidbsd.sourceforge.net/

NO_BUILD=	yes

PLIST_FILES=	sbin/tzdialog share/man/man8/tzdialog.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
