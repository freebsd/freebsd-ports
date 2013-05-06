# Created by: kuriyama
# $FreeBSD$

PORTNAME=	OpenSP
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/openjade/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	This package is a collection of SGML/XML tools called OpenSP

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade \
		--disable-doc-build
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

#MAN1=		onsgmls.1 osgmlnorm.1 ospam.1 ospent.1 osx.1

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${CAT} ${PLIST} | \
		${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} | \
		${AWK} '/^@comment INSTALL_DATA:/ \
			{printf "if ! ${GREP} -q \"%s\" ${PLIST}; then ${ECHO_CMD} \"%s\" >> %s; fi;  %s %s/%s %s/%s\n", \
			$$4, $$4, "${TMPPLIST}", "${INSTALL_DATA}", \
			"${WRKSRC}", $$3, "${PREFIX}", $$4}' | \
		${SH} && \
		${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
