# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Audit
PORTVERSION=	2.2.27
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]+)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for creating easy mail filters

RUN_DEPENDS=	p5-File-HomeDir>=0.61:devel/p5-File-HomeDir \
		p5-File-Tempdir>=0:devel/p5-File-Tempdir \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/*
USE_PERL5=	configure
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	Changes FAQ README
PORTEXAMPLES=	popread proc2ma

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/var/spool/mail|/var/mail|g' \
		${WRKSRC}/lib/Mail/Audit.pm

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${i}  ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor

.include <bsd.port.mk>
