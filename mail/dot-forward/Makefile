# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	dot-forward
PORTVERSION=	0.71
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dot-forward reads sendmail's .forward files under qmail

USES=	gmake

ALL_TARGET=	default

PLIST_FILES=	bin/dot-forward \
		man/man1/dot-forward.1.gz \
		man/cat1/dot-forward.0.gz

do-install:
.for binfile in dot-forward
	${INSTALL_PROGRAM} ${WRKSRC}/${binfile} ${STAGEDIR}${PREFIX}/bin/${binfile}
.endfor

.for manfile in dot-forward.1
	${INSTALL_MAN} ${WRKSRC}/${manfile} ${STAGEDIR}${PREFIX}/man/man1/${manfile}
.endfor

.for catfile in dot-forward.0
	${INSTALL_MAN} ${WRKSRC}/${catfile} ${STAGEDIR}${MAN1PREFIX}/man/cat1/${catfile}
.endfor

.include <bsd.port.mk>
