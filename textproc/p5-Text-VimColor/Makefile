# New ports collection makefile for:	Text::VimColor
# Date created:		2004-07-25
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Text-VimColor
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Syntax color text in HTML or XML using Vim

BUILD_DEPENDS=	p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-File-ShareDir-Install>=0.03:${PORTSDIR}/devel/p5-File-ShareDir-Install \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim
RUN_DEPENDS=	p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim

PERL_CONFIGURE=	yes

MAN1=		text-vimcolor.1
MAN3=		Text::VimColor.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Term-ANSIColor>=3:${PORTSDIR}/devel/p5-Term-ANSIColor
RUN_DEPENDS+=	p5-Term-ANSIColor>=3:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

.include <bsd.port.post.mk>
