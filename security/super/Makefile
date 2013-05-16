# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	super
PORTVERSION=	3.30.0
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.ucolick.org/pub/users/will/ \
		http://www.ucolick.org/~will/RUE/super/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	GPLv1

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		super.1 setuid.1
MAN5=		super.5

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|\.\/mkdir_p -p755|mkdir -p -m 755|g' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/super ${PREFIX}/bin/setuid
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.tab ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.cdmount ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/barebones.tab ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
