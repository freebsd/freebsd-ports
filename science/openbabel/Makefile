# ex:ts=8
# Ports collection makefile for:	openbabel
# Date created:			Jan 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	2.2.3
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Chemistry file translation program

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs

USE_GNOME=	gnomehack gnometarget libxml2
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

MAN1=		obchiral.1 obconformer.1 obenergy.1 obfit.1 obgen.1 obgrep.1 \
		obminimize.1 obprobe.1 obprop.1 obrotamer.1 obrotate.1 \
		openbabel.1 roundtrip.1

PLIST_SUB=	VERSION="${PORTVERSION}"

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${LN} -sf babel.1 ${WRKSRC}/doc/openbabel.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|= babel|= openbabel|g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's| babel| openbabel|g ; \
		 s|"babel|"openbabel|g' ${WRKSRC}/doc/o*.1
	@${REINPLACE_CMD} -e 's|babel$$(EXEEXT)|openbabel$$(EXEEXT)|g' ${WRKSRC}/tools/Makefile.in

.include <bsd.port.post.mk>
