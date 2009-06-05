# New ports collection makefile for:	LaTeX-Driver
# Date created:				1st June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	LaTeX-Driver
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl module of LaTeX Driver

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX-base \
		p5-Cwd>=0:${PORTSDIR}/devel/p5-Cwd \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-IO>=0:${PORTSDIR}/devel/p5-IO \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	latex2ps.1 latex2pdf.1 latex2dvi.1
MAN3=	LaTeX::Driver.3 \
	LaTeX::Driver::Paths.3 \
	LaTeX::Driver::FilterProgram.3

.include <bsd.port.pre.mk>
post-extract:
	@${REINPLACE_CMD} -e 's#<STDIN>#"\r"#g' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
