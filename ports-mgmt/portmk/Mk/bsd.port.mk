#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
#	bsd.port.mk - 940820 Jordan K. Hubbard.
#	This file is in the public domain.
#
# Please view me with 4 column tabs!

# This is the master file for the most common elements to all port
# Makefile in the ports system.  For a more general overview of its
# use and importance, see the Porter's Handbook.

# There are two different types of "maintainers" in the ports framework.
# The maintainer alias of the bsd.port.mk file is listed below in the
# FreeBSD_MAINTAINER entry.  You should consult them if you have any
# questions/suggestions regarding this file.

FreeBSD_MAINTAINER=	eik@FreeBSD.org

# For each port, the MAINTAINER variable is what you should consult for
# contact information on the person(s) to contact if you have questions/
# suggestions about that specific port.  By default (if no MAINTAINER
# is listed), a port is maintained by the subscribers of the ports@FreeBSD.org
# mailing list, and any correspondence should be directed there.
#
# MAINTAINER	- The e-mail address of the contact person for this port
#				  (default: ports@FreeBSD.org).
#
# These are meta-variables that are automatically set to the system
# you are running on.  These are provided in case you need to take
# different actions for different values.
#
# ARCH			- The architecture, as returned by "uname -p".
# OPSYS			- Portability clause.  This is the operating system the
#				  makefile is being used on.  Automatically set to
#				  "FreeBSD," "NetBSD," or "OpenBSD" as appropriate.
# OSREL			- The release version (numeric) of the operating system.
# OSVERSION		- The value of __FreeBSD_version.
# PORTOBJFORMAT	- The object format ("aout" or "elf").
#
# This is the beginning of the list of all variables that need to be
# defined in a port, listed in order that they should be included
# to fit in with existing conventions.  (Exception: MAINTAINER actually
# should appear after EXTRACT_ONLY and before MASTER_SITE_BACKUP).
#
# These variables are used to identify your port.
#
# PORTNAME		- Name of software.  Mandatory.
# PORTVERSION	- Version of software.  Mandatory.
# PORTREVISION	- Version of port.  Optional.  Commonly used to indicate
#				  that an update has happened that affects the port
#				  framework itself, but not the distributed software
#				  (e.g., local patches or Makefile changes).
# PORTEPOCH		- Optional.  In certain odd cases, the PORTREVISION logic
#				  can be fooled by ports that appear to go backwards
#				  numerically (e.g. if port-0.3 is newer than port-1998).
#				  In this case, incrementing PORTEPOCH forces the revision.
#				  Default: 0 (no effect).
# PKGNAME		- Always defined as
#				  ${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.
#				  Do not define this in your Makefile.
# PKGNAMEPREFIX	- Prefix to specify that port is language-specific, etc.
#				  Optional.
# PKGNAMESUFFIX	- Suffix to specify compilation options.  Optional.
# UNIQUENAME	- A name for your port that is globally unique.  By default,
# 				  this is set to ${LATEST_LINK} when LATEST_LINK is set,
# 				  and to ${PKGNAMEPREFIX}${PORTNAME} otherwise.
# DISTNAME		- Name of port or distribution used in generating
#				  WRKSRC and DISTFILES below (default:
#				  ${PORTNAME}-${PORTVERSION}).
# CATEGORIES	- A list of descriptive categories into which this port falls.
#				  Mandatory.
#
# These variable describe how to fetch files required for building the port.
#
# DISTFILES		- Name(s) of archive file(s) containing distribution
#				  (default: ${DISTNAME}${EXTRACT_SUFX}).  Set this to
#				  an empty string if the port doesn't require it.
# EXTRACT_SUFX	- Suffix for archive names (default: .tar.bz2 if USE_BZIP2
#				  is set, .zip if USE_ZIP is set, .tar.gz otherwise).
#				  You never have to set both DISTFILES and EXTRACT_SUFX.
# MASTER_SITES	- Primary location(s) for distribution files if not found
#				  locally.  See bsd.sites.mk for common choices for
#				  MASTER_SITES.
# MASTER_SITE_SUBDIR	- Subdirectory of MASTER_SITES (default: empty).
#				  Will sometimes need to be set to ${PORTNAME} for (e.g.)
#				  MASTER_SITE_SOURCEFORGE.  Only guaranteed to work for
#				  choices of ${MASTER_SITES} defined in bsd.sites.mk.
# PATCHFILES	- Name(s) of additional files that contain distribution
#				  patches (default: none).  make will look for them at
#				  PATCH_SITES (see below).  They will automatically be
#				  uncompressed before patching if the names end with
#				  ".gz", ".bz2" or ".Z".
# PATCH_SITES	- Primary location(s) for distribution patch files
#				  if not found locally.
# DIST_SUBDIR	- Suffix to ${DISTDIR} (default: none).  If set, all
#				  ${DISTFILES} and ${PATCHFILES} will be put in this
#				  subdirectory of ${DISTDIR} (see below).  Also they will
#				  be fetched in this subdirectory from FreeBSD mirror sites.
# ALLFILES		- All of ${DISTFILES} and ${PATCHFILES}.
# IGNOREFILES	- If some of the ${ALLFILES} are not checksum-able, set
#				  this variable to their names (default: empty).
# EXTRACT_ONLY	- If defined, a subset of ${DISTFILES} you want to
#			  	  actually extract (default: none).
#
# (NOTE: by convention, the MAINTAINER entry (see above) should go here.)
#
# These variables are typically set in /etc/make.conf to indicate
# the user's preferred location to fetch files from.  You should
# rarely need to set these.
#
# MASTER_SITE_BACKUP - Backup location(s) for distribution files and patch
#				  files if not found locally and ${MASTER_SITES}/${PATCH_SITES}
#				  (default:
#				  ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/${DIST_SUBDIR}/)
# MASTER_SITE_OVERRIDE - If set, override the MASTER_SITES setting with this
#				  value.
# MASTER_SITE_FREEBSD - If set, only use ${MASTER_SITE_BACKUP} for
#				  MASTER_SITES.
# CD_MOUNTPTS -			List of CDROM mountpoints to look for distfiles under.
#						This variable supercedes CD_MOUNTPT, which is
#						obsolete.
#
# Set these if your port should not be built under certain circumstances.
# These are string variables; you should set them to the reason why
# they are necessary.
#
# RESTRICTED	- Prevent the distribution of distfiles and packages to
#				  the FTP sites or on CDROM (e.g. forbidden by license
#				  considerations).
# NO_CDROM		- Packages and distfiles may not go on CDROM (e.g. must
#				  not be re-sold) but can go on FTP sites.
# NO_PACKAGE	- Port should not be packaged for ftp sites or CDROMs,
#				  but distfiles can be put on ftp sites and CDROMs.
# FORBIDDEN		- Package build should not be attempted because of
#				  security vulnerabilities.
# IGNORE		- Package build should be skipped entirely (e.g.
#				  because of serious unfixable problems in the build,
#				  because it cannot be manually fetched, etc).  Error
#				  logs will not appear on bento, so this should be
#				  used sparingly.
# BROKEN		- Port is believed to be broken.  Package builds will
#				  still be attempted on the bento package cluster to
#				  test this assumption.
#
# In addition to RESTRICTED or NO_CDROM, if only a subset of distfiles
# or patchfiles have redistribution restrictions, set the following
# to the list of such files.
#
# RESTRICTED_FILES - List of files that cannot be redistributed
#				  (default: "${DISTFILES} ${PATCHFILES}" if RESTRICTED
#				  or NO_CDROM is set, empty otherwise).
#
# These variables are booleans, so you don't need to set them to the reason.
#
# IS_INTERACTIVE - Set this if your port needs to interact with the user
#				  during any step in a package build.  User can then decide
#				  to skip this port by setting ${BATCH}, or compiling only
#				  the interactive ports by setting ${INTERACTIVE}.
#				  (Default: not set.)
# USE_SUBMAKE	- Set this if you want that each of the port's main 6 targets
#				  (extract, patch, configure, build, install and package) to be
#				  executed in a separate make(1) process. Useful when one of
#				  the stages needs to influence make(1) variables of the later
#				  stages using ${WRKDIR}/Makefile.inc generated on the fly.
#				  (Default: not set.)
#
# Set these if your port only makes sense to certain architectures.
# They are lists containing names for them (e.g., "alpha i386").
# (Defaults: not set.)
#
# ONLY_FOR_ARCHS - Only build ports if ${ARCH} matches one of these.
# NOT_FOR_ARCHS  - Only build ports if ${ARCH} doesn't match one of these.
#
# These variables control options about how a port gets built and/or
# are shorthand notations for common sets of dependencies.
# Use these if your port uses some of the common software packages. By
# convention these should be set to 'yes', although they only need to be
# defined.  (Defaults: not set, unless explicitly indicated below.)
#
# Note: the distinction between the USE_* and WANT_* variables, and the
# WITH_* and WITHOUT_* variables, are that the former are restricted to
# usage inside the ports framework, and the latter are reserved for user-
# settable options.  (Setting USE_* in /etc/make.conf is always wrong).
#
# USE_BZIP2		- Says that the port tarballs use bzip2, not gzip, for
#				  compression.
# USE_ZIP		- Says that the port distfile uses zip, not tar w/[bg]zip
#				  for compression.
# USE_GCC		- Says that the port requires this version of gcc, either in
#				  the system or installed from a port.
# USE_GMAKE		- Says that the port uses gmake.
# GMAKE			- Set to path of GNU make if not in $PATH (default: gmake).
##
# USE_GETOPT_LONG	- Says that the port uses getopt_long. If OSVERSION
#				  less than 500041, automatically adds devel/libgnugeopt
#				  to LIB_DEPENDS, and pass adjusted values of
#				  CPPFLAGS and LDFLAGS in CONFIGURE_ENV.
#				  Default: not set.
##
# USE_ICONV		- Says that the port uses libiconv.
# USE_GETTEXT		- Says that the port uses GNU gettext (libintl).
##
# USE_PERL5		- Says that the port uses perl5 in one or more of the extract,
#                         patch, build, install or run phases.
# USE_PERL5_BUILD	- Says that the port uses perl5 in one or more of the extract,
#                         patch, build or install phases.
# USE_PERL5_RUN		- Says that the port uses perl5 for running.
# PERL5			- Set to full path of perl5, either in the system or
#				  installed from a port.
# PERL			- Set to full path of perl5, either in the system or
#				  installed from a port, but without the version number.
#				  Use this if you need to replace "#!" lines in scripts.
# PERL_VERSION	- Full version of perl5 (see below for current value).
# PERL_VER		- Short version of perl5 (see below for current value).
# PERL_LEVEL	- Perl version as an integer of the form MNNNPP, where
#					M is major version, N is minor version, and P is
#					the patch level. E.g., PERL_VERSION=5.6.1 would give
#					a PERL_LEVEL of 500601. This can be used in comparisons
#					to determine if the version of perl is high enough,
#					whether a particular dependency is needed, etc.
# PERL_ARCH		- Directory name of architecture dependent libraries
#				  (value: ${ARCH}-freebsd).
# PERL_PORT		- Name of the perl port that is installed
#				  (value: perl5)
# SITE_PERL		- Directory name where site specific perl packages go.
#					This value is added to PLIST_SUB.
# PERL_MODBUILD		- Use Module::Build to configure, build and install
#			  port.
#
# USE_GHOSTSCRIPT	- Says that the port needs ghostscript to both
#					build and run.  Default: not set.
# USE_GHOSTSCRIPT_BUILD	- Says that the port needs ghostscript to build.
#					Default: not set.
# USE_GHOSTSCRIPT_RUN	- Says that the port needs ghostscript to run.
#					Default: not set.
# GHOSTSCRIPT_PORT	- The port that provides postscript functionality.
#					Some installations may wish to override the default
#					to specify a version without X11 and/or localized
#					versions for their nationality.
# WITH_GHOSTSCRIPT_AFPL - If set to Yes, says to use the AFPL
#					version of the ghostscript software instead
#					of the GNU version, which is used otherwise.
##
# USE_BISON		- Says that the port uses bison for building.
##
# USE_IMAKE		- Says that the port uses imake.  Implies USE_X_PREFIX.
# XMKMF			- Set to path of `xmkmf' if not in $PATH (default: xmkmf -a ).
# USE_X_PREFIX	- Says that the port installs in ${X11BASE}.  Implies USE_XLIB.
# USE_XLIB		- Says that the port uses the X libraries.
#
# USE_FREETYPE	- Says that the port uses the freetype print libraries.
# USE_GL		- Says that the port uses libGL (not needed with XFree86 4.x
#				  which already includes this functionality).
# USE_MESA		- Says that the port uses libGL/libglut (deprecated).
# USE_MOTIF		- Says that the port uses a Motif toolkit.  Implies USE_XPM.
# NO_OPENMOTIF		- Says that the port uses a custom Motif toolkit
#			  instead of Openmotif.
#			  Used only when USE_MOTIF is set.
# WANT_LESSTIF		- Says that the port uses Lesstif as Motif toolkit.
#			  Used only when USE_MOTIF is set.  Implies
#			  NO_OPENMOTIF.
# USE_SDL		- Says that the port uses the sdl libraries.
#				See bsd.sdl.mk for more information.
# USE_XPM		- Says that the port uses the xpm graphics libraries.
##
# USE_OPENSSL	- Says that the port relies on the OpenSSL package.
#				  Default: not set.
##
#
# USE_OPENLDAP			- Says that the port uses the OpenLDAP libraries
#						  Implies: WANT_OPENLDAP_VER?=21
# WANT_OPENLDAP_VER		- Legal values are: 21, 22
#						  If set to an unkown value, the port is marked BROKEN.
# WANT_OPENLDAP_SASL	- Says that the system should use OpenLDAP libraries
#						  with SASL support.
#
##
# USE_AUTOTOOLS	-	Says that the port uses various GNU autotools
#					(libtool, autoconf, autoheader, automake et al.)
#					See bsd.autotools.mk for more details.
#					XXX: not currently in active use - this is a placeholder.
##
# USE_JAVA		- Says that the port relies on the Java language.
#				  Implies inclusion of bsd.java.mk.  (Also see
#				  that file for more information on USE_JAVA_*).
#				  Default: not set.
# USE_PYTHON	- Says that the port relies on the Python language.
#				  Implies inclusion of bsd.python.mk. (Also see
#				  that file for more information on USE_PYTHON_*
#				  and USE_PYDISTUTILS).
#				  Default: not set.
# USE_RUBY		- Says that the port relies on the Ruby language.
#				  Implies inclusion of bsd.ruby.mk.  (Also see
#				  that file for more information on USE_RUBY_*).
#				  Default: not set.
# USE_GNUSTEP		- Says that the port relies on the GNUstep system.
#			  Implies the inclusion of bsd.gnustep.mk.
#			  (Also see that file for more information on
#			  USE_GNUSTEP_*).
#			  Default: not set.
##
# USE_GNOME		- A list of the Gnome dependencies the port has (e.g.,
#				  glib12, gtk12).  Implies that the port needs Gnome.
#				  Implies inclusion of bsd.gnome.mk.  See bsd.gnome.mk
#				  or http://www.FreeBSD.org/gnome/docs/porting.html
#				  for more details.
#				  Default: not set.
#
# USE_KDEBASE_VER	- Set to 3 to use the KDE windowing system.
#					  Implies inclusion
#					  of bsd.kde.mk.  Default: not set.
# USE_KDELIBS_VER	- Set to 3 to use the KDE libraries.
#					  Implies inclusion
#					  of bsd.kde.mk.  Default: not set.
# USE_QT_VER		- Set to either 2 or 3 to use the QT libraries.
#					  (Only 3 is currently supported).  Implies inclusion
#					  of bsd.kde.mk.  Default: not set.
#
# USE_LINUX			- Set to yes to say the port needs emulators/linux_base.
#					  Default: not set.
# USE_LINUX_PREFIX	- controls the action of PREFIX (see above).
#
#
# USE_MYSQL			- Add MySQL client dependency.
#					  If no version is given (by the maintainer via the port or
#					  by the user via defined variable), try to find the
#					  currently installed version.  Fall back to default if
#					  necessary (MySQL4.0 = 40).
#
# DEFAULT_MYSQL_VER	- MySQL default version. Can be overriden within a port.
#					  Default: 40.
#
# WANT_MYSQL_VER 	- Maintainer can set an arbitrary version of MySQL by
#					  using it.
#
# BROKEN_WITH_MYSQL	- This variable can be defined if the ports doesn't support
#					  one or more version of MySQL.
#
# MYSQL_VER			- Internal variable for MySQL version.
#
# WITH_MYSQL_VER	- User defined variable to set MySQL version.
#
# USE_RC_SUBR		- Says the ports startup/shutdown script uses the common
#			  	routines found in etc/rc.subr and may need to
#				depend on the sysutils/rc_subr port.
#
# RC_SUBR		- Set to path of rc.subr, defaults to ${LOCALBASE}/etc/rc.subr.
#
# USE_APACHE		- Says that the port relies on an apache webserver.
# APACHE_PORT		- CATEGORY and portname of the prefered port for apache.
#					Default: www/apache13
#					If WITH_APACHE2 is defined defaults to www/apache2
# APXS			- Full path to the prefered apxs binary to configure
#			  apache modules. Default: ${LOCALBASE}/sbin/apxs
#				
#
#
# Dependency checking.  Use these if your port requires another port
# not in the list above.  (Default: empty.)
#
# EXTRACT_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
#				  package depends on in the "extract" stage.  "path" is
#				  the name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the existence
#				  (if it is a full pathname) or search for it in your
#				  $PATH (if it is an executable) and go into "dir" to do
#				  a "make all install" if it's not found.  If the third
#				  field ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.
# PATCH_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
#				  package depends on in the "patch" stage.  "path" is the
#				  name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the existence
#				  (if it is a full pathname) or search for it in your
#				  $PATH (if it is an executable) and go into "dir" to do
#				  a "make all install" if it's not found.  If the third
#				  field ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.
# FETCH_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
#				  package depends in the "fetch" stage.  "path" is the
#				  name of a file if it starts with a slash (/), an
#				  executable otherwise.  make will test for the
#				  existence (if it is a full pathname) or search for
#				  it in your $PATH (if it is an executable) and go
#				  into "dir" to do a "make all install" if it's not
#				  found.  If the third field ("target") exists, it will
#				  be used instead of ${DEPENDS_TARGET}.
# BUILD_DEPENDS - A list of "path:dir[:target]" tuples of other ports this
#				  package depends to build (between the "extract" and
#				  "build" stages, inclusive).  The test done to
#				  determine the existence of the dependency is the
#				  same as FETCH_DEPENDS.  If the third field ("target")
#				  exists, it will be used instead of ${DEPENDS_TARGET}.
# RUN_DEPENDS	- A list of "path:dir[:target]" tuples of other ports this
#				  package depends to run.  The test done to determine
#				  the existence of the dependency is the same as
#				  FETCH_DEPENDS.  This will be checked during the
#				  "install" stage and the name of the dependency will
#				  be put into the package as well.  If the third field
#				  ("target") exists, it will be used instead of
#				  ${DEPENDS_TARGET}.
# LIB_DEPENDS	- A list of "lib:dir[:target]" tuples of other ports this
#				  package depends on.  "lib" is the name of a shared library.
#				  make will use "ldconfig -r" to search for the library.
#				  lib can contain extended regular expressions.
# DEPENDS		- A list of "dir[:target]" tuples of other ports this
#				  package depends on being made first.  Use this only for
#				  things that don't fall into the above four categories.
#				  If the second field ("target") exists, it will be used
#				  instead of ${DEPENDS_TARGET}.
# DEPENDS_TARGET - The default target to execute when a port is calling a
#				  dependency (default: "install").
#
# Conflict checking.  Use if your port cannot be installed at the same time as
# another package.
#
# CONFLICTS      - A list of package name patterns that the port conflicts with.
#                  It's possible to use any shell meta-characters for pattern
#                  matching.
#                  E.g. apache*-1.2* apache*-1.3.[012345] apache-*+ssl_*
#
#
# Various directory definitions and variables to control them.
# You rarely need to redefine any of these except WRKSRC and NO_WRKSUBDIR.
#
# X11BASE		- Where X11 ports install things (default: /usr/X11R6).
# LOCALBASE		- Where non-X11 ports install things (default: /usr/local).
# LINUXBASE		- Where Linux ports install things (default: /compat/linux).
# PREFIX		- Where *this* port installs its files (default: ${X11BASE}
#				  if USE_X_PREFIX is set, ${LINUXBASE} if USE_LINUX_PREFIX
#				  is set, otherwise ${LOCALBASE}).
# MASTERDIR		- Where the port finds patches, package files, etc.  Define
#				  this is you have two or more ports that share most of the
#				  files (default: ${.CURDIR}).
# PORTSDIR		- The root of the ports tree. (default: /usr/ports)
# DISTDIR 		- Where to search for and store copies of original sources
#				  (default: ${PORTSDIR}/distfiles).
# PACKAGES		- A top level directory where all packages go (rather than
#				  going locally to each port). (default: ${PORTSDIR}/packages).
# WRKDIRPREFIX	- The place to root the temporary working directory
#				  hierarchy (default: none).
# WRKDIR 		- A temporary working directory that gets *clobbered* on clean
#				  (default: ${WRKDIRPREFIX}${.CURDIR}/work).
# WRKSRC		- A subdirectory of ${WRKDIR} where the distribution actually
#				  unpacks to.  (Default: ${WRKDIR}/${DISTNAME} unless
#				  NO_WRKSUBDIR is set, in which case simply ${WRKDIR}).
# NO_WRKSUBDIR	- Assume port unpacks directly into ${WRKDIR}.
# PATCHDIR 		- A directory containing any additional patches you made
#				  to port this software to FreeBSD (default:
#				  ${MASTERDIR}/files)
# SCRIPTDIR 	- A directory containing any auxiliary scripts
#				  (default: ${MASTERDIR}/scripts)
# FILESDIR 		- A directory containing any miscellaneous additional files.
#				  (default: ${MASTERDIR}/files)
# PKGDIR 		- A directory containing any package creation files.
#				  (default: ${MASTERDIR})
#
# Variables that serve as convenient "aliases" for your *-install targets.
# Use these like: "${INSTALL_PROGRAM} ${WRKSRC}/prog ${PREFIX}/bin".
#
# INSTALL_PROGRAM - A command to install binary executables.  (By
#					default, also strips them, unless ${STRIP} is
#					overridden to be the empty string).
# INSTALL_SCRIPT  - A command to install executable scripts.
# INSTALL_DATA	  - A command to install sharable data.
# INSTALL_MAN	  - A command to install manpages.  May or not compress,
#					depending on the value of MANCOMPRESSED (see below).
#
# Boolean to control whether manpages are installed.
#
# NO_INSTALL_MANPAGES - Says that the port doesn't want to install any
#						manpages (default: not set, i.e. manpages
#						are installed by default).
#
# Set the following to specify all manpages that your port installs.
# These manpages will be automatically listed in ${PLIST}.  Depending
# on the setting of NOMANCOMPRESS, the make rules will compress the
# manpages for you.
#
# MAN<sect>		- A list of manpages, categorized by section.  For
#				  example, if your port has "man/man1/foo.1" and
#				  "man/mann/bar.n", set "MAN1=foo.1" and "MANN=bar.n".
#				  The available sections chars are "123456789LN".
# MLINKS		- A list of <source, target> tuples for creating links
#				  for manpages.  For example, "MLINKS= a.1 b.1 c.3 d.3"
#				  will do an "ln -sf a.1 b.1" and "ln -sf c.3 d.3" in
#				  appropriate directories.  (Use this even if the port
#				  installs its own manpage links so they will show up
#				  correctly in ${PLIST}.)
# MANPREFIX		- The directory prefix for ${MAN<sect>} and ${MLINKS}
#				  (default: ${PREFIX}).
# MAN<sect>PREFIX - If manual pages of some sections install in different
#				  locations than others, use these (default: ${MANPREFIX}).
# MANCOMPRESSED - This variable can take values "yes", "no" or
#				  "maybe".  "yes" means manpages are installed
#				  compressed; "no" means they are not; "maybe" means
#				  it changes depending on the value of
#				  NOMANCOMPRESS.  The default is "yes" if USE_IMAKE
#				  is set and NO_INSTALL_MANPAGES is not set, and
#				  "no" otherwise.
#
# Set the following to specify all .info files your port installs.
#
# INFO			- A list of .info files (omitting the trailing ".info");
#				  only one entry per document!
# INFO_PATH		- Path, where all .info files will be installed by your
#			  port, relative to ${PREFIX} (default: "share/info" if
#			  ${PREFIX} is equal to /usr and "info" otherwise).
#
# Set the following to specify all documentation your port installs into
# ${DOCSDIR}
#
# PORTDOCS		- A list of files and directories relative to DOCSDIR.
# 				  Shell glob patterns can be used, directories include
# 				  the entire subtree of contained files and directories.
# 				  Should not be set when no documentation files are
# 				  installed (for example because NOPORTDOCS is defined).
# 				  Useful for dynamically generated documentation.
#
# Default targets and their behaviors:
#
# fetch			- Retrieves ${DISTFILES} (and ${PATCHFILES} if defined)
#				  into ${DISTDIR} as necessary.
# fetch-list	- Show list of files that would be retrieved by fetch.
# fetch-recursive - Retrieves ${DISTFILES} (and ${PATCHFILES} if defined),
#				  for port and dependencies into ${DISTDIR} as necessary.
# fetch-recursive-list  - Show list of files that would be retrieved by
#				  fetch-recursive.
# fetch-required-list - Show list of files that would be retrieved by
#				  fetch-required.
# fetch-required - Retrieves ${DISTFILES} (and ${PATCHFILES} if defined),
#				  for port and dependencies that are not already installed
#				  into ${DISTDIR}.
# all-depends-list - Show all directories which are dependencies
#				for this port.
# build-depends-list - Show all directories which are build-dependencies
#				for this port.
# package-depends-list - Show all directories which are
#				package-dependencies for this port.
# run-depends-list - Show all directories which are run-dependencies
#				for this port.
#
# extract		- Unpacks ${DISTFILES} into ${WRKDIR}.
# patch			- Apply any provided patches to the source.
# configure		- Runs either GNU configure, one or more local configure
#				  scripts or nothing, depending on what's available.
# build			- Actually compile the sources.
# install		- Install the results of a build.
# reinstall		- Install the results of a build, ignoring "already installed"
#				  flag.
# deinstall		- Remove the installation.
# deinstall-all	- Remove all installations with the same PKGORIGIN.
# package		- Create a package from an _installed_ port.
# package-recursive - Create a package for a port and _all_ of its dependancies.
# describe		- Try to generate a one-line description for each port for
#				  use in INDEX files and the like.
# checkpatch	- Do a "patch -C" instead of a "patch".  Note that it may
#				  give incorrect results if multiple patches deal with
#				  the same file.
# checksum		- Use distinfo to ensure that your distfiles are valid.
# checksum-recursive - Run checksum in this port and all dependencies.
# makesum		- Generate distinfo (only do this for your own ports!).
# clean		    - Remove ${WRKDIR} and other temporary files used for building.
# clean-depends	- Do a "make clean" for all dependencies.
# config	- Configure options for this port (using ${DIALOG}).
#			Automatically run prior to extract, patch, configure, build,
#			install, and package.
# showconfig	- Display options config for this port
# rmconfig	- Remove the options config for this port
#
# Default sequence for "all" is:
#
#     check-sanity fetch checksum extract patch configure build
#
# Please read the comments in the targets section below; you
# should be able to use the pre-* or post-* targets/scripts
# (which are available for every stage except checksum) or
# override the do-* targets to do pretty much anything you want.
#
# NEVER override the "regular" targets unless you want to open
# a major can of worms.
#
# Set these variables if your port doesn't need some of the steps.
# Note that there are no NO_PATCH or NO_CONFIGURE variables because
# those steps are empty by default.  NO_EXTRACT is not allowed anymore
# since we need to at least create ${WRKDIR}.  Also, NO_CHECKSUM is a user
# variable and is not to be set in a port's Makefile.  See above for NO_PACKAGE.
#
# NO_BUILD		- Use a dummy (do-nothing) build target.
# NO_INSTALL	- Use a dummy (do-nothing) install target.
#
# Here are some variables used in various stages.
#
# For options:
#	OPTIONS		- List of what WITH_<option> options this port accept.  The
#			  format is <option> "<description>" [on|off]
#			  Example:
#				FLEXRESP "Flexible response to events" off
#			 which tell that an option WITH_FLEXRESP exists for this port,
#			 that by default it is not defined, and that the description to
#			 show to a user in the config dialog is "Flexible response to
#			 events".  If you have more than one option, just chain them
#			 into a single variable.  NOTE: To make options work, you need
#			 to include bsd.port.pre.mk before you start testing the
#			 WITH_xyz variables.
#
# For fetch:
#
# FETCH_CMD		- Full path to ftp/http fetch command if not in $PATH
#				  (default: "/usr/bin/fetch -ARr").
# FETCH_BEFORE_ARGS -
#				  Arguments to ${FETCH_CMD} before filename (default: none).
# FETCH_AFTER_ARGS -
#				  Arguments to ${FETCH_CMD} following filename (default: none).
# FETCH_ENV		- Environment to pass to ${FETCH_CMD} (default: none).
# FETCH_REGET	- Times to retry fetching of files on checksum errors (default: 1).
#
# For extract:
#
# EXTRACT_CMD	- Command for extracting archive (default: "bzip2" if
#				  USE_BZIP2 is set, "unzip" if USE_ZIP is set, "gzip"
#				  otherwise).
# EXTRACT_BEFORE_ARGS -
#				  Arguments to ${EXTRACT_CMD} before filename
#				  (default: "-dc").
# EXTRACT_AFTER_ARGS -
#				  Arguments to ${EXTRACT_CMD} following filename
#				  (default: "| tar -xf -").
# EXTRACT_PRESERVE_OWNERSHIP -
#				  Normally, when run as "root", the extract stage will
#				  change the owner and group of all files under ${WRKDIR}
#				  to 0:0.  Set this variable if you want to turn off this
#				  feature.
#
# For makesum:
#
# NO_SIZE			- Don't record size data in distinfo, needed 
#				  when the master site does not report file
#				  sizes, or when multiple valid versions of
#				  a distfile, having different sizes, exist.
#
# For patch:
#
# EXTRA_PATCHES - Define this variable if you have patches not in
#				  ${PATCHDIR}.  This usually happens when you need to
#				  do some pre-processing before some distribution
#				  patches can be applied.  In that case, fetch them as
#				  extra distfiles, put the processed results in
#				  ${WRKDIR}, then point EXTRA_PATCHES to them.
#
#				  The patches specified by this variable will be
#				  applied after the normal distribution patches but
#				  before those in ${PATCHDIR}.
# PATCH_WRKSRC  - Directory to apply patches in (default: ${WRKSRC}).
#
# For configure:
#
# HAS_CONFIGURE	- Says that the port has its own configure script.  The
#				  configure stage will not do anything if this is not set.
# GNU_CONFIGURE	- Set if you are using GNU configure (optional).  Implies
#				  HAS_CONFIGURE.
# PERL_CONFIGURE - Configure using Perl's MakeMaker.  Implies USE_PERL5.
# CONFIGURE_WRKSRC - Directory to run configure in (default: ${WRKSRC}).
# CONFIGURE_SCRIPT - Name of configure script, relative to ${CONFIGURE_WRKSRC}
#				  (default: "Makefile.PL" if PERL_CONFIGURE is set,
#				  "configure" otherwise).
# CONFIGURE_TARGET - The name of target to call when GNU_CONFIGURE is
#				  defined (default: ${MACHINE_ARCH}-portbld-freebsd${OSREL}).
# CONFIGURE_ARGS - Pass these args to configure if ${HAS_CONFIGURE} is set
#				  (default: "--prefix=${PREFIX} ${CONFIGURE_TARGET}" if
#				  GNU_CONFIGURE is set, "CC=${CC} CCFLAGS=${CFLAGS}
#				  PREFIX=${PREFIX} INSTALLPRIVLIB=${PREFIX}/lib
#				  INSTALLARCHLIB=${PREFIX}/lib" if PERL_CONFIGURE is set,
#				  empty otherwise).
# CONFIGURE_ENV - Pass these env (shell-like) to configure if
#				  ${HAS_CONFIGURE} is set.
# CONFIGURE_LOG - The name of configure log file (default: config.log).
#				  It will be printed to the screen if configure fails.
# CONFIGURE_FAIL_MESSAGE - A message displayed to users when configure
# 				           fails (note: this assumes the do-configure
# 				           target has not been overwritten).  This message
# 				           will be passed through /usr/bin/fmt before
# 				           being shown to the user.
#
# For build and install:
#
# MAKEFILE		- Name of the makefile (default: Makefile).
# ALL_TARGET	- Default target for sub-make in build stage (default: all).
# BUILD_WRKSRC  - Directory to do build in (default: ${WRKSRC}).
# MAKE_ENV		- Additional environment vars passed to sub-make in build
#				  and install stages (default: see below).
# MAKE_ARGS		- Any extra arguments to sub-make in build and install
#				  stages (default: none).
#
# For install:
#
# INSTALL_TARGET - Default target for sub-make in install stage
# 				  (default: install).
# INSTALL_WRKSRC - Directory to install from (default: ${WRKSRC}).
# NO_MTREE		- If set, will not invoke mtree from bsd.port.mk from
#				  the "install" target.
# MTREE_FILE	- The name of the mtree file (default: /etc/mtree/BSD.x11.dist
#				  if USE_X_PREFIX is set, /etc/mtree/BSD.local.dist
#				  otherwise.)
# PLIST_DIRS		- Directories to be added to packing list
# PLIST_FILES		- Files and symbolic links to be added to packing list
#
# PLIST			- Name of the `packing list' file (default: ${PKGDIR}/pkg-plist).
#				  Change this to ${WRKDIR}/PLIST or something if you
#				  need to write to it.  (It is not a good idea for a port
#				  to write to any file outside ${WRKDIR} during a normal
#				  build.)
# TMPPLIST		- Name of the `packing list' file after processing
#				  (default: ${WRKDIR}/.PLIST.mktmp).
# PLIST_SUB		- List of "variable=value" pair for substitution in ${PLIST}
# 				  (default: see below).
# INSTALLS_SHLIB - If set, bsd.port.mk will automatically run ldconfig commands
#				  from post-install and also add appropriate @exec/@unexec
#				  directives to directories listed in LDCONFIG_DIRS.
# LDCONFIG_DIRS - List of directories to run ldconfig if
#				  INSTALLS_SHLIB is set (default: %%PREFIX%%/lib).
#				  Note that this is passed through sed just like the
#				  rest of PLIST, so ${PLIST_SUB} substitutions also
#				  apply here.  It is recommended that you use
#				  %%PREFIX%% for ${PREFIX}, %%LOCALBASE%% for
#				  ${LOCALBASE} and %%X11BASE%% for ${X11BASE}.
# DOCSDIR		- Name of the directory to install the packages docs in
#				  (default: ${PREFIX}/share/doc/${PORTNAME}).
# EXAMPLESDIR		- Name of the directory to install the packages examples in
#				  (default: ${PREFIX}/share/examples/${PORTNAME}).
# DATADIR		- Name of the directory to install the packages shared data
#				  in (default: ${PREFIX}/share/${PORTNAME}).
#
# Note that the install target will automatically add manpages (see
# above) and also substitute special sequences of characters (delimited
# by "%%") as defined in PLIST_SUB to generate ${TMPPLIST}.  For
# instance, "OSREL=${OSREL}" in PLIST_SUB causes all occurrences of
# "%%OSREL%%" in ${PLIST} to be substituted by the value of OSREL.
# ${TMPPLIST} is generated before the do-install stage.  If you are
# generating the packing list on-the-fly, make sure it's generated before
# do-install is called!
#
# For package:
#
# NO_LATEST_LINK - Do not install the "Latest" link for package.  Define this
#				  if this port is a beta version of another stable port
#				  which is also in the tree.
# LATEST_LINK    - Install the "Latest" link for the package as ___.  Define
#                 this if the "Latest" link name will be incorrectly determined.
#
# This is used in all stages:
#
# SCRIPTS_ENV	- Additional environment vars passed to scripts in
#                 ${SCRIPTDIR} executed by bsd.port.mk (default: see below).
#
# Finally, variables to change if you want a special behavior.  These
# are for debugging purposes.  Don't set them in your Makefile.
#
# ECHO_MSG		- Used to print all the '===>' style prompts - override this
#				  to turn them off (default: ${ECHO_CMD}).
# PATCH_DEBUG	- If set, print out more information about the patches as
#				  it attempts to apply them.
# PKG_DBDIR		- Where package installation is recorded; this directory
#				must not contain anything else (default: /var/db/pkg).
# PORT_DBDIR		- Where port configuration options are recorded
#				(default: /var/db/ports)
# NO_PKG_REGISTER - Don't register a port installation as a package.
# FORCE_PKG_REGISTER - If set, it will overwrite any existing package
#				  registration information in ${PKG_DBDIR}/${PKGNAME}.
# NO_DEPENDS	- Don't verify build of dependencies.
# NO_CHECKSUM	- Don't verify the checksum.  Typically used when
#				  when you noticed the distfile you just fetched has
#				  a different checksum and you intend to verify if
#				  the port still works with it.
# USE_PACKAGE_DEPENDS - Install dependencies from existing packages instead
#				  of building the port from scratch.
# INSTALL_AS_USER - Define this to install as the current user, intended
#			      for systems where you have no root access.
# DISABLE_SIZE	  - Do not check the size of a distfile even if the SIZE field
#			      has been specified in distinfo.  This is useful
#			      when using an alternate FETCH_CMD.
#
# End of the list of all variables that need to be defined in a port.
# Most port authors should not need to understand anything after this point.
#

.if !defined(OLD_PORTMK)

# Start of pre-makefile section.
.if !defined(AFTERPORTMK)
.include "${PORTSDIR}/devel/portmk/Mk/bsd.port.pre.mk"
.endif
# End of pre-makefile section.

# Start of post-makefile section.
.if !defined(BEFOREPORTMK)
.include "${PORTSDIR}/devel/portmk/Mk/bsd.port.post.mk"
.endif
# End of post-makefile section.

.else

.include "${PORTSDIR}/Mk/bsd.port.mk"

.endif
