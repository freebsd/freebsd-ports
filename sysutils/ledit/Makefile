# ex:ts=8
# Ports collection makefile for:	ledit
# Date created:			Feb 8, 2005
# Whom:				Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$
#

PORTNAME=	ledit
PORTVERSION=	2.00
CATEGORIES=	sysutils
MASTER_SITES=	http://cristal.inria.fr/~ddr/ledit/distrib/src/ \
		http://pauillac.inria.fr/~ddr/ledit/distrib/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Line editor to be used with interactive commands

BUILD_DEPENDS=	camlp5r:${PORTSDIR}/devel/ocaml-camlp5

USE_GMAKE=	yes
USE_OCAML=	yes

ALL_TARGET=	all ledit.opt

PLIST_FILES=	bin/ledit

MAN1=		ledit.1
PORTDOCS=	CHANGES LICENSE README

.include <bsd.port.pre.mk>

do-configure:
	${REINPLACE_CMD} -e '/^BINDIR=/s;/usr/local;${PREFIX};' \
			-e '/^LIBDIR=/s;/usr/local;${PREFIX};' \
			-e '/^MANDIR=/s;/usr/local;${PREFIX};' \
			${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
