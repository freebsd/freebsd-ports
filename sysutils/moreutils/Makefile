# ex:ts=8
# Ports collection makefile for:	moreutils
# Date created:	16 June 2009
# Whom:		Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	moreutils
PORTVERSION=	0.37
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Additional Unix utilities

.if !defined(NO_INSTALL_MANPAGES)
BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook2X \
	${LOCALBASE}/share/xml/docbook/4.4/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-440
.endif

USE_PERL5=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/combine \
		bin/ifne \
		bin/isutf8 \
		bin/lckdo \
		bin/mispipe \
		bin/pee \
		bin/sponge \
		bin/ts \
		bin/vidir \
		bin/vipe \
		bin/zrun

ALL_TARGET=	bins

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		combine.1 \
		ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		pee.1 \
		sponge.1 \
		ts.1 \
		vidir.1 \
		vipe.1 \
		zrun.1

ALL_TARGET+=	mans
MANCOMPRESSED=	no

# portlint will warn about the next line, but we need it this way
OLD_DTD=	/usr/share/xml/docbook/schema/dtd/4.4/docbookx.dtd
NEW_DTD=	${LOCALBASE}/share/xml/docbook/4.4/docbookx.dtd

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.docbook" | ${XARGS} -n 7 -x ${REINPLACE_CMD} -E -e 's|${OLD_DTD}|${NEW_DTD}|g'

post-install:
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${manpage} ${MANPREFIX}/man/man1
.endfor

.endif

.include <bsd.port.post.mk>
