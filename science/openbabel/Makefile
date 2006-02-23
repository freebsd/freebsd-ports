# ex:ts=8
# Ports collection makefile for:	openbabel
# Date created:			Jan 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry file translation program

USE_GCC=	3.4+
USE_GNOME=	gnomehack gnometarget libxml2
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		obchiral.1 obfit.1 obgrep.1 obprop.1 obrotate.1 openbabel.1 

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile on ia64 (gcc internal error)"
.endif

post-extract:
	@${LN} -sf babel.1 ${WRKSRC}/doc/openbabel.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|= babel|= openbabel|g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's| babel| openbabel|g ; \
		 s|"babel|"openbabel|g' ${WRKSRC}/doc/o*.1
	@${REINPLACE_CMD} -e 's|^babel|openbabel|g ; \
		 s|(babel|(openbabel|g ; \
		 s|= babel|= openbabel|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
