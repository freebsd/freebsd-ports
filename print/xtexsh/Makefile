# New ports collection makefile for:   xtexsh
# Date created:         11 August 2001
# Whom:                 Jean-Sebastien Roy <js@jeannot.org>
#
# $FreeBSD$
#

PORTNAME=	xtexsh
PORTVERSION=	1.4.2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mat.univie.ac.at/pub/teschl/xtexsh/
DISTNAME=	${PORTNAME}-1.4-2

MAINTAINER=	js@jeannot.org
COMMENT=	Tcl/Tk-based simple TeX interface

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}-1.4

NO_BUILD=	yes
MAN1=		xtexsh.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/wish,${PREFIX}/bin/wish8.4,; \
		s,/etc,${PREFIX}/etc,; s,bash,sh,' ${WRKSRC}/xtexsh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/xtexsh ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xtexsh.1.gz ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/xtexshrc ${PREFIX}/etc/xtexshrc
	@${MKDIR} ${PREFIX}/share/xtexsh
.for f in xtexsh-mini.png xtexsh.png xtexsh.desktop xtexsh.spec
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/xtexsh
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
