# New ports collection makefile for:	giFT library
# Date created:		Fri Nov 16 02:47:45 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	giFT
PORTVERSION=	0.11.8.1
PORTREVISION=	7
CATEGORIES=	net-p2p
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	An OpenFT, Gnutella and FastTrack p2p network client

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_AUTOTOOLS=	libltdl:22 libtool:22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
USE_RC_SUBR=	yes

MAN1=		giftd.1

DOC_FILES=	AUTHORS COPYING src/ChangeLog \
		INSTALL NEWS QUICKSTART README TODO

.include <bsd.port.pre.mk>

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

post-patch:
	@${REINPLACE_CMD} -e \
	's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/lib/Makefile.in

post-build:
	@${SED} ${SED_SCRIPT} <${FILESDIR}/giftd.sh >${WRKDIR}/giftd.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/giftd.sh ${PREFIX}/etc/rc.d/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
