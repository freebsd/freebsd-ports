# New ports collection makefile for:	perlsh
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	psh
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GR/GREGOR

MAINTAINER=	garga@FreeBSD.org
COMMENT=	New shell made entirely out of a Perl script

PERL_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-install pkg-deinstall

MAN1=	psh.1 \
	pshcomplete.1 \
	pshconfig.1 \
	pshdevel.1
MAN3=	Psh::Builtins::Alias.3 \
	Psh::Builtins::Bg.3 \
	Psh::Builtins::Bind.3 \
	Psh::Builtins::Builtin.3 \
	Psh::Builtins::Cd.3 \
	Psh::Builtins::Complete.3 \
	Psh::Builtins::Delenv.3 \
	Psh::Builtins::Dirs.3 \
	Psh::Builtins::Drives.3 \
	Psh::Builtins::Exit.3 \
	Psh::Builtins::Export.3 \
	Psh::Builtins::Fallback::Env.3 \
	Psh::Builtins::Fallback::Ls.3 \
	Psh::Builtins::Fc.3 \
	Psh::Builtins::Fg.3 \
	Psh::Builtins::Firsttime.3 \
	Psh::Builtins::Forfile.3 \
	Psh::Builtins::Function.3 \
	Psh::Builtins::Hash.3 \
	Psh::Builtins::Help.3 \
	Psh::Builtins::History.3 \
	Psh::Builtins::Jobs.3 \
	Psh::Builtins::Kill.3 \
	Psh::Builtins::Modules.3 \
	Psh::Builtins::Option.3 \
	Psh::Builtins::Package.3 \
	Psh::Builtins::Printenv.3 \
	Psh::Builtins::Readline.3 \
	Psh::Builtins::Rehash.3 \
	Psh::Builtins::Rename.3 \
	Psh::Builtins::Set.3 \
	Psh::Builtins::Setenv.3 \
	Psh::Builtins::Source.3 \
	Psh::Builtins::Strategy.3 \
	Psh::Builtins::Sudo.3 \
	Psh::Builtins::Symbols.3 \
	Psh::Builtins::Theme.3 \
	Psh::Builtins::Tieopt.3 \
	Psh::Builtins::Unalias.3 \
	Psh::Builtins::Which.3 \
	Psh::Completion.3 \
	Psh::Joblist.3 \
	Psh::Locale.3 \
	Psh::Locale::Default.3 \
	Psh::OS.3 \
	Psh::OS::Win.3 \
	Psh::Parser.3 \
	Psh::PerlEval.3 \
	Psh::Strategy.3 \
	Psh::StrategyBunch.3 \
	Psh::Strategy::Auto_cd.3 \
	Psh::Strategy::Auto_resume.3 \
	Psh::Strategy::Bang.3 \
	Psh::Strategy::Brace.3 \
	Psh::Strategy::Darwin_apps.3 \
	Psh::Strategy::Debug.3 \
	Psh::Strategy::Eval.3 \
	Psh::Strategy::Executable.3 \
	Psh::Strategy::Fallback_builtin.3 \
	Psh::Strategy::Perl.3 \
	Psh::Strategy::Perlfunc.3 \
	Psh::Strategy::Perlfunc_heavy.3 \
	Psh::Strategy::Perlscript.3

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
