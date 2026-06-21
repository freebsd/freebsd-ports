code-server on FreeBSD
======================

Overview
--------

code-server allows Visual Studio Code to run on a remote FreeBSD system and
be accessed through a web browser.

After installation, code-server can be started either manually or through
the provided rc.d service.


Service Management
------------------

Enable automatic startup at boot:

    sysrc code_server_enable=YES

Start the service:

    service code-server start

Stop the service:

    service code-server stop

Restart the service:

    service code-server restart

Check service status:

    service code-server status


Accessing code-server
---------------------

By default, code-server listens on TCP port 8080.

Open the following URL in a web browser:

    http://<server>:8080/

Replace <server> with the hostname or IP address of your FreeBSD system.

If a firewall is enabled, ensure that the configured port is reachable from
the client system.


Configuration
-------------

When code-server is started manually, it uses the configuration file of the
current user, usually:

    ~/.config/code-server/config.yaml

When code-server is started through the rc.d service, the configuration file
is created and used at:

    /usr/local/etc/code-server/config.yaml

The configuration file contains settings such as:

    - listen address
    - TCP port
    - authentication settings
    - password

Example:

    bind-addr: 0.0.0.0:8080
    auth: password
    password: my-secret-password


Password
--------

During the first startup, code-server generates a configuration file and a
random password.

When running as a service, the password can be displayed using:

    grep '^password:' /usr/local/etc/code-server/config.yaml

When started manually, the password can be displayed using:

    grep '^password:' ~/.config/code-server/config.yaml


Changing the Listening Address
------------------------------

The listening address and port can be changed in the configuration file.

Example:

    bind-addr: 0.0.0.0:8443

After changing the configuration, restart the service:

    service code-server restart


Extensions

----------

code-server supports many Visual Studio Code extensions.

Extension availability and compatibility depend on the individual extension,
the extension marketplace used, and whether the extension relies on features
that are not available in code-server.

Not all Visual Studio Code extensions are compatible with code-server.

For information about extension compatibility and limitations, see:

    https://coder.com/docs/code-server/FAQ
    https://code.visualstudio.com/api/advanced-topics/remote-extensions


Resource Requirements
---------------------

Building code-server requires substantially more memory than typical FreeBSD
ports.

Systems with insufficient RAM or swap may fail during the build process.

Running code-server generally requires significantly less memory than building
it, but available RAM should still be considered when hosting multiple users
or large development workloads.
