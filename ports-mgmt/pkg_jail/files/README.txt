#
# /usr/ports/local/update/
#
#	Scripts reside here.
#	install then here with:
#	cd /usr/ports/ports-mgmt/pkg_jail && make install-ports
#	/usr/ports should be shared with buildjail and hosts.
#
#
#	Intended to run within a jailed System:
#	---------------------------------------
#
#
#	pkg_update update-ports
#		Starts "make update" for the ports tree.
#
#
#	pkg_update make-packages
#		Builds a port and its dependencies in a clean /usr/local.
#		You should not run this on a server with configuration.
#		Existing packages are used.
#		Extra files in "${PREFIX}" are detected and reported.
#		The default list of ports is "data/make-packages.${hostname}"
#
#
#	pkg_update clean-distfiles
#		Checks all distinfo files and moves the disfiles not found
#		to "/usr/ports/distfiles/Old/".
#
#
#	pkg_update merge-distfiles
#		Copy all disfiles found that do not yet exist on the master
#		directory "/media/ports/distfiles/".
#
#
#	pkg_update clean-packages
#		Synopsis:
#		Find obsolete packages and move them out of the way
#
#		Problem:
#		Installation of a package with multiple dependencys.
#		pkg_add installs the depended package, and its requirements.
#		When the depended package has been updated,
#		The packages that require this are no longer up to date.
#
#		Solution:
#		Use pkg_info on each package and compare the versions
#		with the new versions in the ports tree, if they don't
#		match report it, and move it out of the "All" directory
#		"/usr/ports/packages/All/" into a seperate directory
#		"/usr/ports/packages/Old/" for later cleanup.
#		Then remove all stale links to the moved packages.
#
#	pkg_update clean-openssl-packages
#		Find packages that use openssl and move them out of the way
#
#	pkg_update full-update-jail
#		do full update cycle
#		1) "update-ports" to update the ports tree
#		2) "clean-distfiles" to keep only current distfiles
#		3) "clean-packages" to keep only good packages
#		4) remove all old error logs
#		5) "make-packages" to rebuild missing packages
#
#	pkg_update full-update-jail retry
#		Skip "update-ports" and procced as above.
#
#
#	clean-usr-lib.sh:
#		Cleans the base system after installworld.
#		move old libs to comapt, so old applications keep running,
#		but new applications can only link to up-to-date libs.
#
#
#
#	Intended to everywhere:
#	-----------------------
#
#	pkg_update fetch-distfiles
#		Fetch distfiles for list of ports.
#
#	pkg_update fetch-recursive-distfiles
#		Fetch distfiles for list of ports and their dependecies.
#
#	pkg_update show-extra-files
#		list files in portsdir that are not updated by update-ports
#
#
#
#	Intended to run on a host:
#	--------------------------
#
#	pkg_update dependency-update
#		Try to fix as much dependecy problens in installed ports.
#
#	pkg_update fix-moved-ports
#		Check installed packages for moved ports. Then register
#		the new dir in the old installed package.
#
#	pkg_update add-packages
#		Build a missing port and its missing dpendencies
#		/usr/local is not deleted, on success the port is installed.
#		Existing packages will be used.
#
#	pkg_update list-installed-ports
#		List all installed ports.
#
#	pkg_update show-version-list
#		List installed packages that are not in correct version
#
#	pkg_update show-packages
#		List build packages or report missing for each port
#		recorded in "data/install-packages.${hostname}".
#
#	pkg_update show-missing-installed
#		List build packages or report missing for each port
#		installed on this host.
#
#	pkg_update check-installed-ports
#		Compare the list of installed ports with the list
#		recorded in data/install-packages.${hostname}".
#
#	pkg_update check-update
#		pkg_update check-installed-ports
#		pkg_update show-missing-packages
#		pkg_update show-missing-installed
#
#
#
#	Intended to update a host:
#	--------------------------
#
#	pkg_update show-missing-packages
#		Warn if no package is found for each port
#		recorded in "data/install-packages.${hostname}"
#
#	pkg_update clean
#		Clean all cached information.
#
#	pkg_update make-version-list
#		Make new list of packages that are not in correct version
#
#	pkg_update make-deinstall-list
#		Make new list of ports that are not in correct version
#		and create a script "deinstall.${hostname}" to deinstall
#		all the old ports and the dependend ports in order.
#
#	pkg_update check-reinstall
#		For each package deleted by "make-deinstall-list" warn
#		if no new package is found.
#
#	pkg_update reinstall
#		For each package deleted by "make-deinstall-list" try
#		to install the new package if it exists.
#
#	pkg_update install-packages
#		For each port recorded in "data/install-packages.${hostname}"
#		try to to install the new package if it exists.
#
#	pkg_update show-missing-reinstall
#		For each port recorded from "make-deinstall-list" warn
#		if no new package is found.
#
#	pkg_update make-easy-update
#		Try to generate the ordered sequence of pkg_deinstall
#		and pkg_add commands to update your old packages.
#
#	pkg_update replace-package
#		Overwrite the installed package with a new one and
#		register dependencies and dependant packages.
#		Warning: Don't do this when the ABI of the this
#		package or the ABI of its dependencies has changed.
#
#	pkg_update clean-reinstall
#		For each port recorded from "make-deinstall-list",
#		keep only the ports that have no package installed.
#
#	pkg_update deinstall-packages
#		For each port recorded in "data/install-packages.${hostname}"
#		try to to deinstall the installed port.
#
#
#
#	Files:
#	------
#
#
# /usr/ports/local/update/data/
#
#	Configuration files reside here.
#	create your initial configuration for a build jail:
#	pkg_update list-installed-ports \
#		> /usr/ports/local/update/data/make-packages.jailname
#
# /usr/ports/local/update/log-${host}
#
#	Buildlogs and errorlogs reside here.
#
