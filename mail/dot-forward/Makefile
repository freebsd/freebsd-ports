PORTNAME=	dot-forward
PORTVERSION=	0.71
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dot-forward reads sendmail's .forward files under qmail
WWW=		https://cr.yp.to/dot-forward.html

USES=		gmake groff

ALL_TARGET=	default

PLIST_FILES=	bin/dot-forward \
		share/man/man1/dot-forward.1.gz

do-install:
.for binfile in dot-forward
	${INSTALL_PROGRAM} ${WRKSRC}/${binfile} ${STAGEDIR}${PREFIX}/bin/${binfile}
.endfor

.for manfile in dot-forward.1
	${INSTALL_MAN} ${WRKSRC}/${manfile} ${STAGEDIR}${PREFIX}/share/man/man1/${manfile}
.endfor

.include <bsd.port.mk>
