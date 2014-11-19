# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	qar-bufo
PORTVERSION=	1.3.1
CATEGORIES=	mail
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MWCZANECB
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Generates the Qmail assign and recipients file based on unix groups

USES=		perl5 shebangfix
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	qar-bufo-1.3.1
PLIST_FILES=	bin/qar-bufo man/man1/qar-bufo.1.gz

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

#nothing to configure
do-configure:
	@${ECHO} -n

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} \
		--name=${PORTNAME} --center="${PORTNAME} user guide" \
		${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

.include <bsd.port.post.mk>
