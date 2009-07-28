# ex:ts=8
# Ports collection makefile for:	openbabel
# Date created:			Jan 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	2.2.1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Chemistry file translation program

USE_GNOME=	gnomehack gnometarget libxml2
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

MAN1=		obchiral.1 obconformer.1 obenergy.1 obfit.1 obgen.1 obgrep.1 \
		obminimize.1 obprobe.1 obprop.1 obrotamer.1 obrotate.1 \
		openbabel.1 roundtrip.1

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64 (gcc internal error)
.endif

.if (${OSVERSION} < 700042)
LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python-libs
.endif

post-extract:
	@${LN} -sf babel.1 ${WRKSRC}/doc/openbabel.1

post-patch:
	@${REINPLACE_CMD} -e \
		'/test/s| == | = |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|= babel|= openbabel|g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's| babel| openbabel|g ; \
		 s|"babel|"openbabel|g' ${WRKSRC}/doc/o*.1
	@${REINPLACE_CMD} -e 's|babel$$(EXEEXT)|openbabel$$(EXEEXT)|g' ${WRKSRC}/tools/Makefile.in

.include <bsd.port.post.mk>
